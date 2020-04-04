function [cost]=Cost_function(x,system_parameters,step,allowed_radius,version)
system_parameters(2:4)=x;

extreme_angles=zeros(4,1);
angles=0:step:pi/2;
extreme_angles(1)=Calculate_extreme_angle(angles,true,system_parameters,allowed_radius,version);
extreme_angles(2)=Calculate_extreme_angle(angles,false,system_parameters,allowed_radius,version);

extreme_angles(3)=Calculate_extreme_angle(-angles,true,system_parameters,allowed_radius,version);
extreme_angles(4)=Calculate_extreme_angle(-angles,false,system_parameters,allowed_radius,version);

gamma=min(abs(extreme_angles));
V=2/3*pi*(1-cos(gamma));
cost=-V;
end

function [extreme_angle]=Calculate_extreme_angle(angles,x,system_parameters,allowed_radius,version)
extreme_angle=0;
for i=1:length(angles)
    if x
        phi_ee=[angles(i);0;0];
    else
        phi_ee=[0;angles(i);0];            
    end
    if version==1
        [flag_ser,flag_par]=Sing_v1(system_parameters,phi_ee);
    else
        [flag_ser,flag_par]=Sing_v2(system_parameters,phi_ee);
    end
    [flag]=Collision_check(system_parameters,phi_ee,allowed_radius);
    if flag || flag_ser || flag_par
        extreme_angle=angles(i);
        break;
    end
end
end