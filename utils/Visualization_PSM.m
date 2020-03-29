% This function visualize the simple primitive of PSM in position phi_1,
% phi_2, phi_3 in XYZ parametrization
% Created by Valeria Skvo

function []=Visualization_PSM(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,system_radius)
L_base=system_radius*sin(beta_1);
L_l1=2*system_radius*sin(alpha_1/2);
L_l2=2*system_radius*sin(alpha_2/2);
L_plat=system_radius*sin(beta_2);

figure();
scatter3(0,0,0,'k')
hold on
for i=1:3
    eta_i=(i-1)*2*pi/3;
    
%   Solve the inverse kinematics task for leg
    [q1,q2,q3]=Inverse_kinematics(eta_i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3);
    fprintf("Leg %d: q_1=%0.2f, q_2=%0.2f, q_3=%0.2f\n",i,rad2deg(q1),rad2deg(q2),rad2deg(q3))
    
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

function [O]=visualization_coord(H,system_radius)
[coord_system,O]=new_coordinate_system(H,system_radius);
scatter3(O(1),O(2),O(3),'k')
color=['r','g','b'];
for j=1:3
    X=coord_system(:,j);
    A=X-O;
    quiver3(O(1),O(2),O(3),A(1),A(2),A(3),color(j))    
end
end

function [coord_system,O]=new_coordinate_system(H,system_radius)
coord_system=zeros(3,3);
O=zeros(3,1);
ex=[system_radius/5;0;0;1];
ey=[0;system_radius/5;0;1];
ez=[0;0;system_radius/5;1];
x_axis=H*ex;
y_axis=H*ey;
z_axis=H*ez;
coord_system(:,1)=x_axis(1:3);
coord_system(:,2)=y_axis(1:3);
coord_system(:,3)=z_axis(1:3);
O=H(1:3,4);
end