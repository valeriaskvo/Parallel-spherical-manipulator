function [Kc]=MSA(system_parameters,phi_ee,K_l1,K_l2,K_act)
beta_1=system_parameters(1);
beta_2=system_parameters(2);
alpha_1=system_parameters(3);
alpha_2=system_parameters(4);
system_radius=system_parameters(5);

L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);
L_plat=system_radius*sin(beta_2); 

Kc=zeros(6);
A_support=[zeros(6,42),eye(6,6),zeros(6,30)];
for i=1:3
    eta_i=2*(i-1)*pi/3;
    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    
    q_1=q(1);
    q_2=q(2);
    q_3=q(3);
    
    H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1));
    H_link_1=R_T(Rz(q_1))*R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
    H_link_2=R_T(Rz(q_2))*R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2));
    H_plat=R_T(Rz(q_3))*R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));
    
    % Define the links equations in matrix A
    H=H_base*H_link_1;
    R_link_1=H(1:3,1:3);
    K_23=K_global(L_l1,alpha_1,K_l1,R_link_1);   
    
    H=H*H_link_2;
    R_link_2=H(1:3,1:3);
    K_45=K_global(L_l2,alpha_2,K_l2,R_link_2);
    A_links=[zeros(12,6),-eye(12),zeros(12,30),K_23,zeros(12,18);
             zeros(12,18),-eye(12),zeros(12,30),K_45,zeros(12,6)];
    
    % Define the end-effector equations in matrix A
    H_ee=H*H_plat-H;
    p_plat=H_ee(1:3,4);
    D_scew=[0,-p_plat(3),p_plat(2);
            p_plat(3),0,-p_plat(1);
            -p_plat(2),p_plat(1),0];
    D_6e=[eye(3),D_scew';
          zeros(3,3),eye(3)];
    A_ee=[zeros(6,72),D_6e;
        zeros(6,30),eye(6),D_6e',zeros(6,36)];
    
    % Define the active and passive joint equations in matrix A
    if i==1
        l_r_12=lambda_r(H_base(1:3,1:3)');
        l_e_12=lambda_e(H_base(1:3,1:3)');
        l_r_34=lambda_r(R_link_1');
        l_e_34=lambda_e(R_link_1');
    
        A_aj=[zeros(5,42),l_r_12,-l_r_12,zeros(5,24);
              eye(6,6),eye(6,6),zeros(6,66);
              l_e_12,zeros(1,6),zeros(1,30),K_act*l_e_12,-K_act*l_e_12,zeros(1,24);
              zeros(5,54),l_r_34,-l_r_34,zeros(5,12);
              zeros(6,12),eye(6,6),eye(6,6),zeros(6,54);
              zeros(1,12),l_e_34,zeros(1,36),K_act*l_e_34,-K_act*l_e_34,zeros(1,12)];

        l_r_56=lambda_r(R_link_2');
        l_p_56=lambda_e(R_link_2');
        
        A_pj=[zeros(5,66),l_r_56,-l_r_56;
              zeros(5,24),l_r_56,l_r_56,zeros(5,42);
              zeros(1,24),l_p_56,zeros(1,48);
              zeros(1,30),l_p_56,zeros(1,42)];    
    else
        l_r_34=lambda_r(R_link_1');
        l_e_34=lambda_e(R_link_1');
    
        A_aj=[zeros(5,54),l_r_34,-l_r_34,zeros(5,12);
              zeros(6,12),eye(6,6),eye(6,6),zeros(6,54);
              zeros(1,12),l_e_34,zeros(1,36),K_act*l_e_34,-K_act*l_e_34,zeros(1,12)];

        l_r_12=lambda_r(H_base(1:3,1:3)');
        l_p_12=lambda_e(H_base(1:3,1:3)');
        l_r_56=lambda_r(R_link_2');
        l_p_56=lambda_e(R_link_2');
        
        A_pj=[zeros(5,42),l_r_12,-l_r_12,zeros(5,24);
              l_r_12,l_r_12,zeros(5,66);
              l_p_12,zeros(1,72);
              zeros(1,6),l_p_12,zeros(1,66);
              zeros(5,66),l_r_56,-l_r_56;
              zeros(5,24),l_r_56,l_r_56,zeros(5,42);
              zeros(1,24),l_p_56,zeros(1,48);
              zeros(1,30),l_p_56,zeros(1,42)];
    end
    
    %Aggregate A, B, C and D matrix
    Ai=[A_support;A_links;A_ee;A_aj;A_pj];
    Bi=[zeros(30,6);-eye(6);zeros(42,6)];
    Ci=[zeros(6,36),eye(6),zeros(6,36)];
    Di=zeros(6,6);
    
    %Find the Kc matrix
    Kc=Kc+Di-Ci*Ai^(-1)*Bi;
end
end


function K_global=K_global(r,alpha,K,R)
L=[0,-(r*sin(alpha/2)),0;
   (r*sin(alpha/2)),0,-(r*cos(alpha/2));
   0,(r*cos(alpha/2)),0];
R=R(1:3,1:3);
K_22=K;
A=K(1:3,1:3);
B=K(1:3,4:6);
C=K(4:6,1:3);
D=K(4:6,4:6);
K_11=[A, B-A*L;C+L*A, D-C*L+L*B-L*A*L];
K_12=[-A, -B;-C-L*A, -D-L*B];
K_21=[-A, -B+A*L;-C, -D+C*L];

R_global=[R,zeros(3,3),zeros(3,3),zeros(3,3);
          zeros(3,3),R,zeros(3,3),zeros(3,3);
          zeros(3,3),zeros(3,3),R,zeros(3,3);
          zeros(3,3),zeros(3,3),zeros(3,3),R];
K_global=R_global*[K_11,K_12;K_21,K_22]*R_global';
end

function l_r=lambda_r(R)
l_r=[eye(3),zeros(3,3);
    zeros(2,3),R(1:2,1:3)];
end

function l_e=lambda_e(R)
l_e=[zeros(1,3),R(3,1:3)];
end