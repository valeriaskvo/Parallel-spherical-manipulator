function Kc=MSA(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,R,Ix,Iy,Iz,A,K_act,d,angle)
%Define the rigid support equations in matrix A
A_support=[zeros(6,42),eye(6,6),zeros(6,30)];

%Define the stiffnes of links in matrix A
K_L1=K_link(R,alpha_1,Ix,Iy,Iz,A)^(-1);
K_L2=K_link(R,alpha_2,Ix,Iy,Iz,A)^(-1);

Kc=zeros(6);
for i=1:3
    eta_i=2*(i-1)*pi/3;
    [theta,mu_1,mu_2]=Inverse_kinematics(i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,angle);
    K_23=K_global(R,alpha_1,K_L1,Q(-(beta_1+pi),eta_i));
    K_45=K_global(R,alpha_2,K_L2,Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta));
    A_links=[zeros(12,6),-eye(12),zeros(12,30),K_23,zeros(12,18);
             zeros(12,18),-eye(12),zeros(12,30),K_45,zeros(12,6)];
         
%Define the end-effector equations in matrix A
    D_6e=D(d,phi_1,phi_2,phi_3,eta_i);
    A_ee=[zeros(6,72),D_6e;
          zeros(6,30),eye(6),D_6e',zeros(6,36)];

%Define the active joint equations in matrix A
    l_r_12=lambda_r(Q(-(beta_1+pi),eta_i));
    l_e_12=lambda_e(Q(-(beta_1+pi),eta_i));
    A_aj=[zeros(5,42),l_r_12,-l_r_12,zeros(5,24);
      eye(6,6),eye(6,6),zeros(6,66);
      l_e_12,l_e_12,zeros(1,30),K_act*l_e_12,-K_act*l_e_12,zeros(1,24)];

%Define the passive joints equations in matrix A
    l_r_34=lambda_r(Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta));
    l_p_34=lambda_e(Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta));
    l_r_56=lambda_r(Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta)*Q(alpha_2,mu_1));
    l_p_56=lambda_e(Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta)*Q(alpha_2,mu_1));

    A_pj=[zeros(5,54),l_r_34,-l_r_34,zeros(5,12);
      zeros(5,12),l_r_34,l_r_34,zeros(5,54);
      zeros(1,12),l_p_34,zeros(1,60);
      zeros(1,18),l_p_34,zeros(1,54);
      zeros(5,66),l_r_56,-l_r_56;
      zeros(5,24),l_r_56,l_r_56,zeros(5,42);
      zeros(1,24),l_p_56,zeros(1,48);
      zeros(1,30),l_p_56,zeros(1,42)];

%Aggregate A, B, C and D matrix
    Ai=[A_support;A_links;A_ee;A_aj;A_pj];
    Bi=[zeros(30,6);-eye(6);zeros(42,6)];
    Ci=[zeros(6,36),-eye(6),zeros(6,36)];
    Di=zeros(6,6);
%Find the Kc matrix
    Kc=Kc+Di-Ci*Ai^(-1)*Bi; 
end
end