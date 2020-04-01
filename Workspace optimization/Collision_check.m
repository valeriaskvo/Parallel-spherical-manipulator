function [flag]=Collision_check(system_parameters,phi_ee,allowed_rad)
beta_1=system_parameters(1);
alpha_1=system_parameters(3);
alpha_2=system_parameters(4);
system_radius=system_parameters(5);

L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);

O_w=zeros(3);
O_v=zeros(3);

for i=1:3
    eta_i=(i-1)*2*pi/3;

    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    q1=q(1);
    q2=q(2);
    q3=q(3);
    
    H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1))*R_T(Rz(q1));
    H_link_1=R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2))*R_T(Rz(q2));
    H=H_base*H_link_1;
    O_w(:,i)=H(1:3,4);
    
    H_link_2=R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(Rz(q3));
    H=H*H_link_2;
    O_v(:,i)=H(1:3,4);
end

condition_1=sqrt((O_w(1:3,1)-O_v(1:3,2)).'*(O_w(1:3,1)-O_v(1:3,2)))<allowed_rad || sqrt((O_w(1:3,2)-O_v(1:3,3)).'*(O_w(1:3,2)-O_v(1:3,3)))<allowed_rad || sqrt((O_w(1:3,3)-O_v(1:3,1)).'*(O_w(1:3,3)-O_v(1:3,1)))<allowed_rad;
condition_2=sqrt((O_w(1:3,1)-O_w(1:3,2)).'*(O_w(1:3,1)-O_w(1:3,2)))<allowed_rad || sqrt((O_w(1:3,2)-O_w(1:3,3)).'*(O_w(1:3,2)-O_w(1:3,3)))<allowed_rad || sqrt((O_w(1:3,1)-O_w(1:3,3)).'*(O_w(1:3,1)-O_w(1:3,3)))<allowed_rad;

flag=condition_1 || condition_2;
end