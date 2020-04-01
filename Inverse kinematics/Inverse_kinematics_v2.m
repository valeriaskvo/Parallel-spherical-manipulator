function [q_v2]=Inverse_kinematics_v2(system_parameters,phi_ee)
q_v2=zeros(4,1);
for i=1:3
   eta_i=(i-1)*2/3*pi;
   q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
   if i==1
       q_v2(1)=q(1);
       q_v2(2)=q(2);
   else
       q_v2(i+1)=q(2);
   end
end
end