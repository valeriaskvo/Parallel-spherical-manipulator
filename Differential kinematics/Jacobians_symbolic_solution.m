addpath(genpath('..\..\PSM git'))

clear all;
close all;

syms beta_1 beta_2 alpha_1 alpha_2 eta_i system_radius real;
syms q_1 q_2 q_3 real;
syms dq_1 dq_2 dq_3 real;

system_parameters=[beta_1; beta_2; alpha_1; alpha_2; system_radius];
q_leg=[q_1; q_2; q_3];

%% Compute the jacobian matrix for only one leg
R_q1=Rz(q_1)*Rx(alpha_1);
R_q2=Rz(q_2)*Rx(alpha_2);
R_q3=Rz(q_3);
R=Rz(-eta_i)*Rx(pi+beta_1)*R_q1*R_q2*R_q3*Rx(beta_2)*Rz(eta_i)

dR_q1=diff(R_q1,q_1)*dq_1;
dR_q2=diff(R_q2,q_2)*dq_2;
dR_q3=diff(R_q3,q_3)*dq_3;
dR=Rz(-eta_i)*Rx(pi+beta_1)*(dR_q1*(R_q2*R_q3)+R_q1*(dR_q2*R_q3+R_q2*dR_q3))*Rx(beta_2)*Rz(eta_i);

S=simplify(expand(dR(1:3,1:3)*R(1:3,1:3)'));

w=[-S(2,3);S(1,3);-S(1,2)];
J_q1=simplify(expand(diff(w,dq_1)));
J_q2=simplify(expand(diff(w,dq_2)));
J_q3=simplify(expand(diff(w,dq_3)));

J=[J_q1,J_q2,J_q3]

matlabFunction(J,'file','J_leg.m','vars',[{eta_i} {system_parameters} {q_leg}])

%% Jacobian matrix from end-effector in XYZ parametrization
syms phi_1 phi_2 phi_3 real;
syms dphi_1 dphi_2 dphi_3 real;

phi_ee=[phi_1; phi_2; phi_3];

R_phi_1=Rx(phi_1);
R_phi_2=Ry(phi_2);
R_phi_3=Rz(phi_3);

dR_phi_1=diff(R_phi_1,phi_1)*dphi_1;
dR_phi_2=diff(R_phi_2,phi_2)*dphi_2;
dR_phi_3=diff(R_phi_3,phi_3)*dphi_3;

R=R_phi_1*R_phi_2*R_phi_3;

dR=dR_phi_1*(R_phi_2*R_phi_3)+R_phi_1*(dR_phi_2*R_phi_3+R_phi_2*dR_phi_3);
dR=simplify(dR);

S=simplify(dR*R');

w=[-S(2,3);S(1,3);-S(1,2)]

A_1=expand(subs(diff(w,dphi_1)));
A_2=expand(subs(diff(w,dphi_2)));
A_3=expand(subs(diff(w,dphi_3)));

J=simplify([A_1,A_2,A_3])

matlabFunction(J,'file','J_ee.m','vars',{phi_ee})

% Compute Jacobians for each legs with different joint angles

syms q_11 q_21 q_31 real;
syms q_12 q_22 q_32 real;
syms q_13 q_23 q_33 real;

J_1=J_leg(0,system_parameters,[q_11;q_21;q_31]);
J_q_11=J_1(:,1);
J_q_21=J_1(:,2);
J_q_31=J_1(:,3);

J_2=J_leg(2/3*pi,system_parameters,[q_12;q_22;q_32]);
J_q_12=J_2(:,1);
J_q_22=J_2(:,2);
J_q_32=J_2(:,3);

J_3=J_leg(4/3*pi,system_parameters,[q_13;q_23;q_33]);
J_q_13=J_3(:,1);
J_q_23=J_3(:,2);
J_q_33=J_3(:,3);

%% Rearranged jacobians into the form [J_act, J_pass]
% You can check the singularity by the matrix S=J_pass'*J_pass if this
% matrix has an incomplete rank, then the orientation phi_1, phi_2, phi_3
% is singular
% The transverse matrix from end-effector can also be singular.

% VERSION 1: low links control
n=size(J_q_11);
J_act=[J_q_11, -J_q_12, zeros(n);
       zeros(n), -J_q_12, J_q_13]
J_pass=[J_q_21, J_q_31, -J_q_22, -J_q_32, zeros(n), zeros(n);
        zeros(n), zeros(n), -J_q_22, -J_q_32, J_q_23, J_q_33]
J_rel=-inv(J_pass'*J_pass)*J_pass'*J_act;
J_relation=[1,0,0;
            J_rel(1,:);
            J_rel(2,:)];
J_end=inv(J_ee(phi_1,phi_2,phi_3));
J=J_end*J_1*J_relation;

% VERSION 2: intermediate links control
n=size(J_q_11);
J_act=[J_q_11, J_q_21, -J_q_22, zeros(n);
       zeros(n),zeros(n),-J_q_22, J_q_32]
J_pass=[J_q_31, -J_q_12, -J_q_32, zeros(n), zeros(n);
        zeros(n),-J_q_12, -J_q_32, J_q_13, J_q_33]
S=J_pass'*J_pass;

J_rel=-inv(J_pass'*J_pass)*J_pass'*J_act;
J_relation=[1,0,0,0;
            0,1,0,0;
            J_rel(1,:)];
J_end=inv(J_ee(phi_1,phi_2,phi_3));
J=J_end*J_1*J_relation;