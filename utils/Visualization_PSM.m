% This function visualize the simple primitive of PSM in position phi_1,
% phi_2, phi_3 in XYZ parametrization
% Created by Valeria Skvo

function []=Visualization_PSM(system_parameters,phi_ee)
beta_1=system_parameters(1);
beta_2=system_parameters(2);
alpha_1=system_parameters(3);
alpha_2=system_parameters(4);
system_radius=system_parameters(5);

L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);
L_plat=system_radius*sin(beta_2);

figure();
scatter3(0,0,0,'k')
hold on
visualization_coord(eye(4),system_radius);
for i=1:3
    eta_i=(i-1)*2*pi/3;
    
%   Solve the inverse kinematics task for leg
    q=Inverse_kinematics(eta_i,system_parameters,phi_ee);
    q1=q(1);
    q2=q(2);
    q3=q(3);
    
    fprintf("Leg %d: q_1%d=%0.2f [deg], q_2%d=%0.2f, q_3%d=%0.2f\n",i,i,rad2deg(q1),i,rad2deg(q2),i,rad2deg(q3))
    
%   Forward kinematics for leg
    H_base=R_T(Rz(-eta_i))*Ty(L_base)*R_T(Rx(pi+beta_1))*R_T(Rz(q1));
    H_link_1=R_T(Rx(alpha_1/2))*Ty(-L_l1)*R_T(Rx(alpha_1/2))*R_T(Rz(q2));
    H_link_2=R_T(Rx(alpha_2/2))*Ty(-L_l2)*R_T(Rx(alpha_2/2))*R_T(Rz(q3));
    H_plat=R_T(Rx(beta_2))*Ty(-L_plat)*R_T(Rz(eta_i));

%   Leg visualization with coordinate system 
    keypoints=zeros(3,5);
    H=H_base;
    keypoints(:,2)=visualization_coord(H,system_radius);
    H=H*H_link_1;
    keypoints(:,3)=visualization_coord(H,system_radius);
    H=H*H_link_2;
    keypoints(:,4)=visualization_coord(H,system_radius);
    H=H*H_plat;
    keypoints(:,5)=visualization_coord(H,system_radius);
    
    plot3(keypoints(1,:),keypoints(2,:),keypoints(3,:),'k','LineWidth',1)           
end

xlabel('x');
ylabel('y');
zlabel('z');

grid on
xlim([-2.5*system_radius 2.5*system_radius])
ylim([-2.5*system_radius 2.5*system_radius])
zlim([0 2.5*system_radius])
end