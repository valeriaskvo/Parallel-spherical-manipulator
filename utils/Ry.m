% Rotation matrix around y-axis
% Created by Valeria Skvo

function Ry=Ry(alpha)
Ry=[cos(alpha), 0, sin(alpha);
    0,1,0;
    -sin(alpha), 0,cos(alpha)];
end