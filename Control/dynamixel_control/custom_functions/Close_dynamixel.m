function []=Close_dynamixel(IDs)
global PROTOCOL_VERSION COMM_SUCCESS
global ADDR_TORQUE_ENABLE

global port_num lib_name

for i=1:length(IDs)
    DXL_ID=IDs(i);
    write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, 0);
    dxl_comm_result = getLastTxRxResult(port_num, PROTOCOL_VERSION);
    dxl_error = getLastRxPacketError(port_num, PROTOCOL_VERSION);
    if dxl_comm_result ~= COMM_SUCCESS
        fprintf('%s\n', getTxRxResult(PROTOCOL_VERSION, dxl_comm_result));
    elseif dxl_error ~= 0
        fprintf('%s\n', getRxPacketError(PROTOCOL_VERSION, dxl_error));
    else
        fprintf('Dynamixel [ID:%d] has been successfully disconnected \n',DXL_ID);
    end
end

% Close port
closePort(port_num);

% Unload Library
unloadlibrary(lib_name);
end