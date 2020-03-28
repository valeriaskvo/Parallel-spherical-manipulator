addpath(genpath('..\..\PSM git'))

clear all;
close all;

syms beta_1 beta_2 alpha_1 alpha_2 eta_i system_radius real;
syms q_1 q_2 q_3 real;
syms dq_1 dq_2 dq_3 real;

geometric_parameters=[beta_1 beta_2 alpha_1 alpha_2];
q_leg=[q_1, q_2, q_3];

% STEP 1: Compute the jacobian matrix for only one leg:
L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);
L_plat=system_radius*sin(beta_2);

R_q1=Rz(q_1);
R_q2=Rz(q_2);
R_q3=Rz(q_3);

H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1));
H_link_1=R_T(R_q1)*R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
H_link_2=R_T(R_q2)*R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(R_q3);
H_plat=R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));

H=expand(H_base*H_link_1*H_link_2*H_plat);

% dR_q1=diff(R_q1,q_1)*dq_1;
% dR_q2=diff(R_q2,q_2)*dq_2;
% dR_q3=diff(R_q3,q_3)*dq_3;
% H_link_1=R_T(dR_q1)*R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
% H_link_2=R_T(dR_q2)*R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(dR_q3);

dH=expand(H_base*H_link_1*H_link_2*H_plat);

S=simplify(expand(dH(1:3,1:3)*H(1:3,1:3)'));

v=[diff(H(1:3,4),q_1),diff(H(1:3,4),q_2),diff(H(1:3,4),q_3)];
w=[-S(2,3);S(1,3);-S(1,2)];

J_q1=simplify(expand(subs(w,[dq_2,dq_3],[0,0]))/dq_1);
J_q2=simplify(expand(subs(w,[dq_1,dq_3],[0,0]))/dq_2);
J_q3=simplify(expand(subs(w,[dq_1,dq_2],[0,0]))/dq_3);

J_v=simplify(v);
J_w=simplify([J_q1,J_q2,J_q3])

J=[J_v;J_w];

matlabFunction(J,'file','J_leg.m','vars',[{eta_i} {beta_1} {beta_2} {alpha_1} {alpha_2} {system_radius} {q_leg}])
% 
% % StEP 2: Compute Jacobians for each legs with different joint angles
% 
% syms theta_1 mu_11 mu_21 real;
% syms theta_2 mu_12 mu_22 real;
% syms theta_3 mu_13 mu_23 real;
% 
% beta_1=0;
% % beta_2=rad2deg(90);
% % alpha_1=rad2deg(90);
% % alpha_2=rad2deg(90);
% 
% J_1=J_leg(0,beta_1,beta_2,alpha_1,alpha_2,[theta_1,mu_11,mu_21]);
% J_theta_1=J_1(1:3,1);
% J_mu_11=J_1(1:3,2);
% J_mu_21=J_1(1:3,3);
% 
% J_2=J_leg(2/3*pi,beta_1,beta_2,alpha_1,alpha_2,[theta_2,mu_12,mu_22]);
% J_theta_2=J_2(1:3,1);
% J_mu_12=J_2(1:3,2);
% J_mu_22=J_2(1:3,3);
% 
% J_3=J_leg(4/3*pi,beta_1,beta_2,alpha_1,alpha_2,[theta_3,mu_13,mu_23]);
% J_theta_3=J_3(1:3,1);
% J_mu_13=J_3(1:3,2);
% J_mu_23=J_3(1:3,3);
% 
% % % STEP 3: Rearranged jacobians into the form [J_act, J_pass]
% % % VERSION 1: low links control
% % J_act=[J_theta_1, J_theta_2, J_theta_3]
% % J_pass=[J_mu_11, J_mu_21, J_mu_12, J_mu_22, J_mu_13, J_mu_23]
% 
% % VERSION 2: intermediate links control
% J_act=[J_theta_1, J_mu_11, J_mu_12, J_mu_13];
% J_pass=[J_mu_21, J_theta_2, J_mu_22, J_theta_3, J_mu_23];
% 
% A=simplify(expand(J_pass'*J_pass))
% 
% % g=-pinv(J_pass)*J_act
% % 
% % 
% % Jacobians from end-effector
% syms phi_1 phi_2 phi_3 real;
% syms dphi_1 dphi_2 dphi_3 real;
% 
% R_phi_1=Rx(phi_1);
% R_phi_2=Ry(phi_2);
% R_phi_3=Rz(phi_3);
% 
% dR_phi_1=diff(R_phi_1,phi_1)*dphi_1;
% dR_phi_2=diff(R_phi_2,phi_2)*dphi_2;
% dR_phi_3=diff(R_phi_3,phi_3)*dphi_3;
% 
% R=R_phi_1*R_phi_2*R_phi_3;
% 
% dR=dR_phi_1*(R_phi_2*R_phi_3)+R_phi_1*(dR_phi_2*R_phi_3+R_phi_2*dR_phi_3);
% dR=simplify(dR);
% 
% S=simplify(dR*R');
% 
% w=[-S(2,3);S(1,3);-S(1,2)]
% 
% A_1=expand(subs(w,[dphi_2,dphi_3],[0,0]))/dphi_1;
% A_2=expand(subs(w,[dphi_1,dphi_3],[0,0]))/dphi_2;
% A_3=expand(subs(w,[dphi_1,dphi_2],[0,0]))/dphi_3;
% 
% J_ee=simplify([A_1,A_2,A_3])
% 
% matlabFunction(J_ee,'file','J_ee.m','vars',[phi_1 phi_2 phi_3])