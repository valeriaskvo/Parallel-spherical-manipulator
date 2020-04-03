addpath(genpath('..\..\PSM git'))

clear all;
close all;

syms beta_1 beta_2 alpha_1 alpha_2 eta_i system_radius real;
syms q_1 q_2 q_3 real;

system_parameters=[beta_1; beta_2; alpha_1; alpha_2; system_radius];
q_leg=[q_1; q_2; q_3];

% %% Transformation matrices for one leg
% L_base=system_radius*sin(beta_1);
% L_l1=2*system_radius*sin(alpha_1/2);
% L_l2=2*system_radius*sin(alpha_2/2);
% L_plat=system_radius*sin(beta_2);
% 
% H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1));
% H_link_1=R_T(Rz(q_1))*R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2));
% H_link_2=R_T(Rz(q_2))*R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(Rz(q_3));
% H_plat=R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));
% 
% H_full=H_base*H_link_1*H_link_2*H_plat
% matlabFunction(H_full,'file','H_leg.m','vars',[{eta_i} {system_parameters} {q_leg}])
% 
% %% The forward kinematics problem for a parallel spherical manipulator:
% % find the orientation of the platform that correspond to the angles in
% % active joints.
% % Orientation of platform can be described by XYZ euler angles orientation
% 
% syms phi_1 phi_2 phi_3 real;
% syms q_11 q_12 q_13 real;
% 
% R_ee=Rx(phi_1)*Ry(phi_2)*Rz(phi_3);
% 
% % Then the angles phi_1, phi_2 and phi_3 can be find from rotation matrix
% % by the following way:

% syms r11 r12 r13 r21 r22 r23 r31 r32 r33 real;
% 
% R=[r11, r12, r13;
%    r21, r22, r23;
%    r31, r32, r33];
% 
% phi_1=-atan2(r23,r33);
% phi_2=asin(r13);
% phi_3=-atan2(r12,r11);
% 
% phi_ee=[phi_1; phi_2; phi_3];
% 
% matlabFunction(phi_ee,'file','R_to_eulXYZ.m','vars',{R})

%% The solution to direct kinematics is that we find the missing angles in
% each leg. The optimization function in this case:

syms q_11 q_21 q_31 real;
syms q_12 q_22 q_32 real;
syms q_13 q_23 q_33 real;

q_i1=[q_11;q_21;q_31];
q_i2=[q_12;q_22;q_32];
q_i3=[q_13;q_23;q_33];

H_1=H_leg(0,system_parameters,q_i1);
H_2=H_leg(2/3*pi,system_parameters,q_i2);
H_3=H_leg(4/3*pi,system_parameters,q_i3);

P_1=H_1(1:3,4);
P_2=H_2(1:3,4);
P_3=H_3(1:3,4);
position_error=(P_1-P_2)'*(P_1-P_2)+(P_1-P_3)'*(P_1-P_3)+(P_2-P_3)'*(P_2-P_3);

R_1=H_1(1:3,1:3);
R_2=H_2(1:3,1:3);
R_3=H_3(1:3,1:3);

orientation_error_1=-(R_1(1:3,1)'*R_2(1:3,1)+R_1(1:3,2)'*R_2(1:3,2)+R_1(1:3,3)'*R_2(1:3,3));
orientation_error_2=-(R_1(1:3,1)'*R_3(1:3,1)+R_1(1:3,2)'*R_3(1:3,2)+R_1(1:3,3)'*R_3(1:3,3));
orientation_error_3=-(R_2(1:3,1)'*R_3(1:3,1)+R_2(1:3,2)'*R_3(1:3,2)+R_2(1:3,3)'*R_3(1:3,3));
orientation_error=orientation_error_1+orientation_error_2+orientation_error_3;

% Add the weights to the position error and rotation error;
syms w1 w2 real;
w=[w1;w2];
error=w1*position_error+w2*orientation_error

matlabFunction(error,'file','Weighted_error.m','vars',[{system_parameters},{w},{q_i1},{q_i2},{q_i3}])
