% Compute the matix for singularity checking in PSM which controlled by
% intermediate links actuators
% Created by Valeria Skvo

function [S]=Sing_v2(system_parameters,phi_ee)
J_gen=zeros(3,9);
for i=1:3
    eta_i=(i-1)*2/3*pi;
    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    J_i=J_leg(eta_i,system_parameters,q);
    J_gen(:,3*(i-1)+1:3*(i-1)+3)=J_i;
end
n=size(J_gen(:,1));
J_pass=[J_gen(:,3),-J_gen(:,4),-J_gen(:,6),zeros(n),zeros(n);
        zeros(n),-J_gen(:,4),-J_gen(:,6),J_gen(:,7),J_gen(:,9)]; 
S=J_pass'*J_pass;
end