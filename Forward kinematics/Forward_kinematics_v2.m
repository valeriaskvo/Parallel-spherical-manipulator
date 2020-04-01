function [phi]=Forward_kinematics_v2(system_parameters,q)
x0=zeros(5,1);
for i=1:3
   eta_i=(i-1)*2/3*pi;
   q_0=Inverse_kinematics(eta_i,system_parameters,[0;0;0]);
   if i==1
      x0(1)=q_0(3);
   else
      x0(2*(i-1):2*(i-1)+1)=[q_0(1);q_0(3)];
   end
end
options = optimoptions('fmincon','Algorithm','sqp');
x=fmincon(@(x)Cost_function_v2(x,system_parameters,q),x0,[],[],[],[],[],[],[],options);
H_1=H_leg(0,system_parameters,[q(1);q(2);x(1)]);
phi=R_to_eulXYZ(H_1(1:3,1:3));
end

function [error]=Cost_function_v2(x,system_parameters,q)
q_i1=[q(1);q(2);x(1)];
q_i2=[x(2);q(3);x(3)];
q_i3=[x(4);q(4);x(5)];
w=[1;10^3];

error=Weighted_error(system_parameters,w,q_i1,q_i2,q_i3);
end