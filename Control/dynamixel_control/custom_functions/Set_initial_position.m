% Created by Valeria Skvo

function []=Set_initial_position(IDs,control_mode,goal_position)
global pos_lim_max pos_lim_min

pos_threshold=(double(pos_lim_max)-double(pos_lim_min))*0.001*pi/2048;

if control_mode~="position"
    Torque_enable_or_disable(IDs,0)
    Change_contol_mode(IDs,"position")
    Torque_enable_or_disable(IDs,1)
end

while 1
    Write_position(IDs,goal_position,[])
    position=Read_position(IDs);
    err=position-goal_position;
    if sum(abs(err)>pos_threshold)==0
        break;
    else
        pause(0.001)
    end
end

if control_mode~="position"
    Torque_enable_or_disable(IDs,0)
    Change_contol_mode(IDs,control_mode)
    Torque_enable_or_disable(IDs,1)
end
end