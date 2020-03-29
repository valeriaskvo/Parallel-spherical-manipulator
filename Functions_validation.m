close all;
clear all;

addpath(genpath('..\PSM git')); % Folder name

beta_1=deg2rad(0);
beta_2=deg2rad(90);
alpha_1=deg2rad(90);
alpha_2=deg2rad(90);
system_radius=100;

phi_1=deg2rad(0);
phi_2=deg2rad(0);
phi_3=deg2rad(0);

phi=[phi_1;
     phi_2;
     phi_3];

dphi=[deg2rad(0.01);
      deg2rad(0.01);
      deg2rad(0.01)];

phi_0=phi-dphi;

dq_v1=zeros(3,1);
dq_v2=zeros(4,1);
q=zeros(3);

% Visualization_PSM(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,system_radius)
% 
for i=1:3
   eta_i=(i-1)*2/3*pi;
   [q_1,q_2,q_3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi(1),phi(2),phi(3));
   q_end=[q_1,q_2,q_3]';
   J = J_leg(eta_i,beta_1,beta_2,alpha_1,alpha_2,system_radius,q_end');
   
   q(i,:)=[q_1,q_2,q_3];
   
   [q_1,q_2,q_3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi_0(1),phi_0(2),phi_0(3));
   q_zeros=[q_1,q_2,q_3]';
   dq=q_end-q_zeros;
   
   J_eq=J*dq;
   
   dq_v1(i)=dq(1);
   
   if i==1
       dq_v2(1)=dq(1);
       dq_v2(2)=dq(2);
   else
       dq_v2(i+1)=dq(2);
   end
   
end

dphi
% 
% J_ver_1=J_v1(beta_1,beta_2,alpha_1,alpha_2,system_radius,phi_1,phi_2,phi_3);
% dEE_v1=J_ver_1*dq_v1
% 
% J_ver_2=J_v2(beta_1,beta_2,alpha_1,alpha_2,system_radius,phi_1,phi_2,phi_3);
% dEE_v2=J_ver_2*dq_v2

[S]=Sing_v1(beta_1,beta_2,alpha_1,alpha_2,system_radius,phi_1,phi_2,phi_3)

[~,s,~]=svd(S)