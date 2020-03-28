% Rotation matrix around x-axis
% Created by Valeria Skvo

function Rx=Rx(alpha)
Rx=[1,0,0;
    0,cos(alpha),-sin(alpha);
    0,sin(alpha),cos(alpha)];
end