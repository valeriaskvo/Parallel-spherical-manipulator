addpath(genpath('..\..\PSM git'))

clear all;
syms phi_1 phi_2 phi_3 beta_1 beta_2 eta_i alpha_1 alpha_2 q_1 q_2 q_3 angle T real;

ez=[0;0;1];
ex=[1;0;0];

% Step_1. Find the q_1 angle without translation part
v_z_i=Rx(phi_1)*Ry(phi_2)*Rz(phi_3)*Rz(eta_i)'*Rx(beta_2)'*ez;
w_z_i=Rz(-eta_i)*Rx(pi+beta_1)*Rz(angle)*Rx(alpha_1)*ez;
equation=v_z_i'*w_z_i-cos(alpha_2);
equation=subs(equation,sin(angle),2*T/(1+T^2));
equation=subs(equation,cos(angle),(1-T^2)/(1+T^2))*(1+T^2);
equation=simplify(expand(equation));
b_equation=diff(equation,T);
A_theta=simplify(diff(b_equation,T)/2);
B_theta=simplify(subs(b_equation,T,0));
C_theta=simplify(subs(equation,T,0));
matlabFunction(A_theta,'File', 'A_q1','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3});
matlabFunction(B_theta,'File', 'B_q1','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3});
matlabFunction(C_theta,'File', 'C_q1','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3});

%Step_2. Find the q_2 angle without translation part
e_z_i=Rx(phi_1)*Ry(phi_2)*Rz(phi_3)*ez;
v_z_i=Rz(-eta_i)*Rx(pi+beta_1)*Rz(q_1)*Rx(alpha_1)*Rz(angle)*Rx(alpha_2)*ez;
equation=sum(e_z_i.*v_z_i)-cos(beta_2);
equation=subs(equation,sin(angle),2*T/(1+T^2));
equation=subs(equation,cos(angle),(1-T^2)/(1+T^2))*(1+T^2);
equation=simplify(expand(equation));
b_equation=diff(equation,T);
A_mu_1=simplify(diff(b_equation,T)/2);
B_mu_1=simplify(subs(b_equation,T,0));
C_mu_1=simplify(subs(equation,T,0));
matlabFunction(A_mu_1,'File', 'A_q2','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1});
matlabFunction(B_mu_1,'File', 'B_q2','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1});
matlabFunction(C_mu_1,'File', 'C_q2','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1});

% %Step_3. Find the q_3 angle by the cos theorem
v_x_i=Rz(-eta_i)*Rx(pi+beta_1)*Rz(q_1)*Rx(alpha_1)*Rz(q_2)*Rx(alpha_2)*ex;
v_x=Rz(phi_1)*Ry(phi_2)*Rz(phi_3)*Rz(eta_i)'*Rx(beta_2)'*ex;

cos_q3=(v_x_i'*v_x)/(sqrt(v_x_i'*v_x_i)*sqrt(v_x'*v_x));
q_3=-acos(cos_q3);

matlabFunction(q_3,'File', 'q3_find','Vars', {eta_i, beta_1, beta_2, alpha_1, alpha_2, phi_1, phi_2, phi_3, q_1, q_2});