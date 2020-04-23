function []=Torque_enable_or_disable(IDs,torque)
global port_num PROTOCOL_VERSION
global ADDR_TORQUE_ENABLE torque_enable torque_disable
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_TORQUE_ENABLE, 1);

if torque==1
    Group_write(IDs,groupwrite,1,torque_enable,"CHANGE TORQUE ENABLE");
else
    Group_write(IDs,groupwrite,1,torque_disable,"CHANGE TORQUE DISABLE");
end
end