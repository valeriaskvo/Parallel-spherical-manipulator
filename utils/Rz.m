% Rotation matrix around z-axis
% Created by Valeria Skvo

function Rz=Rz(alpha)
Rz=[cos(alpha), -sin(alpha), 0;
    sin(alpha), cos(alpha),0;
    0,0,1];
end