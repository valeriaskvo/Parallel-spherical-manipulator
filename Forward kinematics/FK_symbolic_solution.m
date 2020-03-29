addpath(genpath('..\..\PSM git'))

clear all;
close all;

syms beta_1 beta_2 alpha_1 alpha_2 eta_i system_radius real;
syms q_1 q_2 q_3 real;

% Transformation matrices for one leg
L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);
L_plat=system_radius*sin(beta_2);

H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1));
H_link_1=R_T(Rz(q_1))*R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
H_link_2=R_T(Rz(q_2))*R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(Rz(q_3));
H_plat=R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));

H_full=H_base*H_link_1*H_link_2*H_plat
q_leg=[q_1, q_2, q_3];
matlabFunction(H_full,'file','H_leg.m','vars',[{eta_i} {beta_1} {beta_2} {alpha_1} {alpha_2} {system_radius} {q_leg}])

% The forward kinematics problem for a parallel spherical manipulator:
% find the orientation of the platform that correspond to the angles in
% active joints.
% Orientation of platform can be described by XYZ euler angles orientation

syms phi_1 phi_2 phi_3 real;
syms q_11 q_12 q_13 real;

ez=[0;0;1];

v_z_i=Rx(phi_1)*Ry(phi_2)*Rz(phi_3)*Rz(eta_i)'*Rx(beta_2)'*ez
w_z_i=Rz(-eta_i)*Rx(pi+beta_1)*Rz(q_11)*Rx(alpha_1)*ez


