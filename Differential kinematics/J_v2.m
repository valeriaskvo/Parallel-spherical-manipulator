% Jacobian for case when PSM controlled by intermediate links actuators
% Created by Valeria Skvo

function [J]=J_v2(beta_1,beta_2,alpha_1,alpha_2,system_radius,phi_1,phi_2,phi_3)
J_gen=zeros(3,9);
for i=1:3
    eta_i=(i-1)*2/3*pi;
    [q_1,q_2,q_3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3);
    J_i=J_leg(eta_i,beta_1,beta_2,alpha_1,alpha_2,system_radius,[q_1,q_2,q_3]);
    J_gen(:,3*(i-1)+1:3*(i-1)+3)=J_i;
end
n=size(J_gen(:,1));
J_act=[J_gen(:,1),J_gen(:,2),-J_gen(:,5),zeros(n);
       zeros(n),zeros(n),-J_gen(:,5),J_gen(:,8)];
J_pass=[J_gen(:,3),-J_gen(:,4),-J_gen(:,6),zeros(n),zeros(n);
        zeros(n),-J_gen(:,4),-J_gen(:,6),J_gen(:,7),J_gen(:,9)]; 
J_rel=-pinv(J_pass)*J_act;
J_relation=[1,0,0,0;
            0,1,0,0;
            J_rel(1,:)];
J_1=J_gen(:,1:3);
J_end=inv(J_ee(phi_1,phi_2,phi_3));
J=J_end*J_1*J_relation;
end