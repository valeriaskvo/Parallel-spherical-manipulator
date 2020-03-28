% Transform the rotation matrix in type which includes the translation part
% Created by Valeria Skvo

function R_T=R_T(R)
R_T=[R,zeros(3,1);
    zeros(1,3),1];
end
