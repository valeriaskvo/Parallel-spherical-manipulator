% Jacobian for case when PSM controlled by low links actuators
% Created by Valeria Skvo

function [J]=J_v1(system_parameters,phi_ee)
J_gen=zeros(3,9);
for i=1:3
    eta_i=(i-1)*2/3*pi;
    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    J_i=J_leg(eta_i,system_parameters,q);
    J_gen(:,3*(i-1)+1:3*(i-1)+3)=J_i;
end
n=size(J_gen(:,1));
J_act=[J_gen(:,1),-J_gen(:,4),zeros(n);
       zeros(n),-J_gen(:,4),J_gen(:,7)];
J_pass=[J_gen(:,2),J_gen(:,3),-J_gen(:,5),-J_gen(:,6),zeros(n),zeros(n);
        zeros(n),zeros(n),-J_gen(:,5),-J_gen(:,6),J_gen(:,8),J_gen(:,9)];
J_rel=-pinv(J_pass)*J_act;
J_relation=[1,0,0;
            J_rel(1,:);
            J_rel(2,:)];
J_1=J_gen(:,1:3);
J_end=inv(J_ee(phi_ee));
J=J_end*J_1*J_relation;
end