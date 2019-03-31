clear all;
syms angle;
%VJM
% Parameters of system
i=3;
alpha_1=pi/4;
alpha_2=pi/4;
beta_1=0;
beta_2=pi-(beta_1+alpha_1+alpha_2);

% Orientation of end-effector by ZYZ parametrization
phi_1=0;
phi_2=0;
phi_3=0;

%Link parameters
R=0.1;
Ix=1.5/1e2;
Iy=5.5;
Iz=4.5;
A=0.02^2*pi;

%End-effector platform parameters
d=[0.02;0.02;2*R*sin(beta_2/2)];

%Stiffnes of actuator
K_act=6*1e6;

%Force
F=4.9;

Kc=MSA(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,R,Ix,Iy,Iz,A,K_act,d,angle)
Kc=VJM(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,R,Ix,Iy,Iz,A,K_act,angle)







