function [Kc]=VJM(system_parameters,phi_ee,K_l1,K_l2,K_act)
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
for i=1:3
    eta_i=2*(i-1)*pi/3;
    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    
    q_1=q(1);
    q_2=q(2);
    q_3=q(3);
    
    H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1));
    H_link_1=R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
    H_link_2=R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2));
    H_plat=R_T(Rz(q_3))*R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));
    
    H0=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat;
    H0(1:3,4)=[0;0;0];
    H0=H0';
    
    if i==1
        dH_q1=H_base*dRz(0)*H_link_1*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
        J_q1=Jnum(dH_q1);
        dH_q2=H_base*R_T(Rz(q_1))*H_link_1*dRz(0)*H_link_2*R_T(Rz(q_3))*H_plat*H0;
        J_q2=Jnum(dH_q2);
    else
        dH_q1=H_base*dRz(q_1)*H_link_1*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
        J_q1=Jnum(dH_q1);
        dH_q2=H_base*R_T(Rz(q_1))*H_link_1*dRz(0)*H_link_2*R_T(Rz(q_3))*H_plat*H0;
        J_q2=Jnum(dH_q2);
    end
    
    dH_q3=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dRz(q_3)*H_plat*H0;
    J_q3=Jnum(dH_q3);
    
    dH_1=H_base*R_T(Rz(q_1))*H_link_1*dTx*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_1=Jnum(dH_1);
    dH_2=H_base*R_T(Rz(q_1))*H_link_1*dTy*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_2=Jnum(dH_2);
    dH_3=H_base*R_T(Rz(q_1))*H_link_1*dTz*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_3=Jnum(dH_3);
    dH_4=H_base*R_T(Rz(q_1))*H_link_1*dRx(0)*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_4=Jnum(dH_4);
    dH_5=H_base*R_T(Rz(q_1))*H_link_1*dRy(0)*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_5=Jnum(dH_5);
    dH_6=H_base*R_T(Rz(q_1))*H_link_1*dRz(0)*R_T(Rz(q_2))*H_link_2*R_T(Rz(q_3))*H_plat*H0;
    J_6=Jnum(dH_6);
    
    dH_7=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dTx*R_T(Rz(q_3))*H_plat*H0;
    J_7=Jnum(dH_7);
    dH_8=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dTy*R_T(Rz(q_3))*H_plat*H0;
    J_8=Jnum(dH_8);
    dH_9=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dTz*R_T(Rz(q_3))*H_plat*H0;
    J_9=Jnum(dH_9);
    dH_10=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dRx(0)*R_T(Rz(q_3))*H_plat*H0;
    J_10=Jnum(dH_10);
    dH_11=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dRy(0)*R_T(Rz(q_3))*H_plat*H0;
    J_11=Jnum(dH_11);
    dH_12=H_base*R_T(Rz(q_1))*H_link_1*R_T(Rz(q_2))*H_link_2*dRz(0)*R_T(Rz(q_3))*H_plat*H0;
    J_12=Jnum(dH_12);
    
    if i==1
        J_theta=[J_q1,J_q2,J_1,J_2,J_3,J_4,J_5,J_6,J_7,J_8,J_9,J_10,J_11,J_12];
        J_pass=J_q3;
        n=1;
        K_t=[K_act, 0, zeros(1,6), zeros(1,6);
             0, K_act, zeros(1,6), zeros(1,6);
             zeros(6,1),zeros(6,1),K_l1,zeros(6);
             zeros(6,1),zeros(6,1),zeros(6),K_l2];
    else
        J_theta=[J_q2,J_1,J_2,J_3,J_4,J_5,J_6,J_7,J_8,J_9,J_10,J_11,J_12];
        J_pass=[J_q1,J_q3];
        n=2;
        K_t=[K_act, zeros(1,6), zeros(1,6);
             zeros(6,1),K_l1,zeros(6);
             zeros(6,1),zeros(6),K_l2];       
    end
    Kci=inv([J_theta*inv(K_t)*J_theta', J_pass;
            J_pass',zeros(n)]);
    Kc=Kc+Kci(1:6,1:6);
end
end

function [H]=dTx()
H=zeros(4);
H(1,4)=1;
end

function [H]=dTy()
H=zeros(4);
H(2,4)=1;
end

function [H]=dTz()
H=zeros(4);
H(3,4)=1;
end

function [H]=dRx(alpha)
H=zeros(4);
H(1:3,1:3)=Rx(pi/2+alpha);
H(1,1)=0;
end

function [H]=dRy(alpha)
H=zeros(4);
H(1:3,1:3)=Ry(pi/2+alpha);
H(2,2)=0;
end

function [H]=dRz(alpha)
H=zeros(4);
H(1:3,1:3)=Rz(pi/2+alpha);
H(3,3)=0;
end

function [J]=Jnum(dH)
J=[dH(1,4); dH(2,4); dH(3,4); dH(3,2); dH(1,3); dH(2,1)];
end