% Created by Valeria Skvo

function []=Change_contol_mode(IDs,control_mode)
global port_num PROTOCOL_VERSION

global ADDR_OPERATING_MODE current_control_mode pwm_control_mode position_control_mode velocity_control_mode
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_OPERATING_MODE, 1);
if control_mode=="current"
    Group_write(IDs,groupwrite,1,current_control_mode,"CONTROL MODE")
elseif control_mode=="pwm"
    Group_write(IDs,groupwrite,1,pwm_control_mode,"CONTROL MODE")
elseif control_mode=="position"
    Group_write(IDs,groupwrite,1,position_control_mode,"CONTROL MODE")
elseif control_mode=="velocity"
    Group_write(IDs,groupwrite,1,velocity_control_mode,"CONTROL MODE")
end
end