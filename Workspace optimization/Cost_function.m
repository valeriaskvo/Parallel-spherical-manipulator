function [singular_coints]=Cost_function(x,system_parameters,phi_set,allowed_radius,version)
system_parameters(2:4)=x;
if version==1
    [flag_ser,flag_par]=Sing_v1(system_parameters,[0;0;0]);
else
    [flag_ser,flag_par]=Sing_v2(system_parameters,[0;0;0]);
end

if flag_ser || flag_par
    singular_coints=length(phi_set);
else
    [workspace]=Workspace_calculation(system_parameters,phi_set,allowed_radius,version);
    singular_coints=length(phi_set)-sum(workspace==0,'all');
end
end