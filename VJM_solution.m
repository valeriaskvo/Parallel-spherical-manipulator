clear all;
syms angle;
%VJM
% Parameters of system
i=1;
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

%Stiffnes of actuator
K_act=6*1e6;

%Force
F=4.9;

load Orientations avalible_orientations;
x=[];
y=[];
z=[];
n=size(avalible_orientations);
for i=1:n(1)
    Kc=VJM(beta_1,beta_2,alpha_1,alpha_2,avalible_orientations(i,1),avalible_orientations(i,2),avalible_orientations(i,3),R,Ix,Iy,Iz,A,K_act,angle);
    x(i)=avalible_orientations(i,1);
    y(i)=avalible_orientations(i,3);
    z(i)=F*fix(Kc(1,6));
    disp(Kc);
end
contourf(x,y,z);