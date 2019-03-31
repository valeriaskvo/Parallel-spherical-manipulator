function Kc=VJM(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,R,Ix,Iy,Iz,A,K_act,angle)
%Define the K_theta matrix
K_L1=K_link(R,alpha_1,Ix,Iy,Iz,A)^(-1);
K_L2=K_link(R,alpha_2,Ix,Iy,Iz,A)^(-1);
K_theta=[K_act, zeros(1,6), zeros(1,6);
         zeros(6,1),K_L1,zeros(6,6);
         zeros(6,1),zeros(6,6),K_L2];

Kc=zeros(6);
for i=1:3
    eta_i=2*(i-1)*pi/3;
    [theta,mu_1,mu_2]=Inverse_kinematics(i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,angle);
    T_end=R_T(Rz(phi_1)*Ry(phi_2)*Rz(phi_3));
    
%Define the J_theta matrix
    T=R_T(Q(-(beta_1+pi),eta_i));
    T_d=R_T(Q_d(alpha_1,theta));
    J_theta=J(T,T_d,T_end,true);

    T=T*R_T(Q(alpha_1,theta));
    T_d=Trans_d(1,0,0);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=Trans_d(0,1,0);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=Trans_d(0,0,1);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=R_T(Rx_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];
    T_d=R_T(Ry_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];
    T_d=R_T(Rz_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];

    T=T*R_T(Q(alpha_2,mu_1));
    T_d=Trans_d(1,0,0);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=Trans_d(0,1,0);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=Trans_d(0,0,1);
    J_theta=[J_theta,J(T,T_d,T_end,false)];
    T_d=R_T(Rx_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];
    T_d=R_T(Ry_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];
    T_d=R_T(Rz_d(0));
    J_theta=[J_theta,J(T,T_d,T_end,true)];

%Define the J_q matrix
    T=R_T(Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta));
    T_d=R_T(Q_d(alpha_2,mu_1));
    J_q=J(T,T_d,T_end,true);

    T=T*R_T(Q(alpha_2,mu_1));
    T_d=R_T(Q_d(0,mu_2));
    J_q=[J_q,J(T,T_d,T_end,true)];

%Find the Kc matrix
    K_c0=inv(J_theta*K_theta*transpose(J_theta));
    K_cq=inv(transpose(J_q)*inv(K_c0)*J_q)*transpose(J_q)*inv(K_c0);
    
    Kc=Kc+K_c0-K_c0*J_q*K_cq;
end
end