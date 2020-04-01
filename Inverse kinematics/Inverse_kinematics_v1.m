function [q_v1]=Inverse_kinematics_v1(system_parameters,phi_ee)
q_v1=zeros(3,1);
for i=1:3
   eta_i=(i-1)*2/3*pi;
   q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
   q_v1(i)=q(1);
end
end