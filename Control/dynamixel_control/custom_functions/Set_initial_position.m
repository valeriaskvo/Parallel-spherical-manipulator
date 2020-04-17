% Created by Valeria Skvo

function []=Set_initial_position(IDs,control_mode,goal_position)
global ADDR_POSITION_LIMIT_max ADDR_POSITION_LIMIT_min pos_lim_max pos_lim_min

pos_threshold=(double(pos_lim_max)-double(pos_lim_min))*0.001*pi/2048;

global port_num PROTOCOL_VERSION
global ADDR_TORQUE_ENABLE torque_enable torque_disable
global ADDR_OPERATING_MODE current_control_mode position_control_mode
if control_mode~="position"
    for i=1:length(IDs)
        DXL_ID=IDs(i);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, torque_disable);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_OPERATING_MODE, position_control_mode);
        write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_POSITION_LIMIT_max, pos_lim_max);
        write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_POSITION_LIMIT_min, pos_lim_min);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, torque_enable);
    end
end

while 1
    Write_position(IDs,goal_position)
    position=Read_position(IDs);
    err=position-goal_position;
    if sum(abs(err)>pos_threshold)==0
        break;
    else
        pause(0.001)
    end
end

if control_mode~="position"
    for i=1:length(IDs)
        DXL_ID=IDs(i);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, torque_disable);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_OPERATING_MODE, current_control_mode);
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, torque_enable);
    end
end
end