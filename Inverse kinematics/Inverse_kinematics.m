function [q_1,q_2,q_3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3)
% Step 1: Find the theta angle without translation part
A=A_q1(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3);
B=B_q1(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3);
C=C_q1(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3);
q_1=Inverse_kinematic_solver(A,B,C,0);
        
if q_1~=inf
    A=A_q2(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1);
    B=B_q2(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1);
    C=C_q2(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1);
    q_2=Inverse_kinematic_solver(A(1),B(1),C(1),1);
    if q_2~=inf
        q_3=q3_find(eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1, q_2);
    else
        q_3=inf;
    end
else
    q_2=inf;
    q_3=inf;
end
end

function theta=Inverse_kinematic_solver(A,B,C,mu_1)
if A==0 && B==0
    theta=inf;
elseif A==0
    theta=2*atan(-B/C);
elseif B^2<4*A*C
    theta=inf;
elseif B^2==4*A*C
    theta=2*atan(-B/(2*A));
elseif mu_1
    theta=2*atan((-B-sqrt(B^2-4*A*C))/(2*A));
else
    theta=2*atan((-B+sqrt(B^2-4*A*C))/(2*A));
end
end