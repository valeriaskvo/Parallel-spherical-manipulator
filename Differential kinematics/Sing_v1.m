% Compute the matix for singularity checking in PSM which controlled by low
% links actuators
% Created by Valeria Skvo

function [S]=Sing_v1(beta_1,beta_2,alpha_1,alpha_2,system_radius,phi_1,phi_2,phi_3)
J_gen=zeros(3,9);
for i=1:3
    eta_i=(i-1)*2/3*pi;
    [q_1,q_2,q_3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3);
    J_i=J_leg(eta_i,beta_1,beta_2,alpha_1,alpha_2,system_radius,[q_1,q_2,q_3]);
    J_gen(:,3*(i-1)+1:3*(i-1)+3)=J_i;
end
n=size(J_gen(:,1));
J_pass=[J_gen(:,2),J_gen(:,3),-J_gen(:,5),-J_gen(:,6),zeros(n),zeros(n);
        zeros(n),zeros(n),-J_gen(:,5),-J_gen(:,6),J_gen(:,8),J_gen(:,9)];
S=J_pass'*J_pass;
end