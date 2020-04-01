% This function generates a spiral path along the surface of the upper
% half of the sphere in the orientation space from zero rotation
% Flag "vis" allow to show the optimization path.
% Created by Valeria Skvo

function [phi_set,cartesian_space]=Spiral_path_on_maximum_ws(step,vis)
alpha_arr=0:step:2*pi-step;
beta_arr=step:step:pi/2;
system_radius=1;

if vis
    figure();
    scatter3(0,0,0,'w')
    hold on
    xlim([-system_radius*1.5 system_radius*1.5])
    ylim([-system_radius*1.5 system_radius*1.5])
    zlim([-system_radius/5 system_radius*1.5])
    axis equal
    xlabel('x')
    ylabel('y')
    zlabel('z')
    title('The spiral path in orientation space');
    O=visualization_coord(Tz(system_radius),system_radius);
    path=[O'];
end 

cartesian_space=[0,0,1];
phi_set=[0,0,0];
for i=1:length(beta_arr)
   for j=1:length(alpha_arr)
       alpha=alpha_arr(j);
       beta=beta_arr(i);
       
       R=Rz(alpha)*Ry(beta)*Rz(-alpha);
       eulXYZ = rotm2eul(R,'XYZ');
       phi_set=[phi_set;eulXYZ];
       v=R*[0;0;1];
       cartesian_space=[cartesian_space;v'];
       if vis
           H=R_T(R)*Tz(system_radius);
           O=visualization_coord(H,system_radius);
           path=[path;O'];
       end
   end
end

if vis
    plot3(path(:,1),path(:,2),path(:,3),'k',"LineWidth",1)
end
end