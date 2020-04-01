function [workspace]=Workspace_calculation(system_parameters,phi_set,allowed_radius,version)

workspace=zeros(length(phi_set),1);
for i=1:length(phi_set)
    phi_ee=phi_set(i,:)';
    if version==1
        [flag_ser,flag_par]=Sing_v1(system_parameters,phi_ee);
    else
        [flag_ser,flag_par]=Sing_v2(system_parameters,phi_ee);
    end
    [flag]=Collision_check(system_parameters,phi_ee,allowed_radius);
    if flag_ser
        workspace(i)=1;
    elseif flag_par
        workspace(i)=2;
    elseif flag
        workspace(i)=3;
    end    
end