% Created by Valeria Skvo

function [portFlag,baudRateFlag]=Launch_dynamixel(IDs, control_mode)
Dynamixel_mx106_inf()
global BAUDRATE DEVICENAME PROTOCOL_VERSION COMM_SUCCESS
global lib_name
lib_name = '';

if strcmp(computer, 'PCWIN')
  lib_name = 'dxl_x86_c';
elseif strcmp(computer, 'PCWIN64')
  lib_name = 'dxl_x64_c';
elseif strcmp(computer, 'GLNX86')
  lib_name = 'libdxl_x86_c';
elseif strcmp(computer, 'GLNXA64')
  lib_name = 'libdxl_x64_c';
elseif strcmp(computer, 'MACI64')
  lib_name = 'libdxl_mac_c';
end

% Load Libraries
if ~libisloaded(lib_name)
    [notfound, warnings] = loadlibrary(lib_name, 'dynamixel_sdk.h', 'addheader', 'port_handler.h', 'addheader', 'packet_handler.h','addheader', 'group_sync_write.h', 'addheader', 'group_sync_read.h');
end

% Initialize PortHandler Structs
% Set the port path
% Get methods and members of PortHandlerLinux or PortHandlerWindows
global port_num
port_num = portHandler(DEVICENAME);

% Initialize PacketHandler Structs
packetHandler();

% Open port
if (openPort(port_num))
    fprintf('Succeeded to open the port!\n');
else
    unloadlibrary(lib_name);
    fprintf('Failed to open the port!\n');
    input('Press any key to terminate...\n');
    return;
end

% Set port baudrate
if (setBaudRate(port_num, BAUDRATE))
    fprintf('Succeeded to set the baudrate!\n');
else
    unloadlibrary(lib_name);
    fprintf('Failed to set the baudrate!\n');
    input('Press any key to terminate...\n');
    return;
end

portFlag=openPort(port_num);
baudRateFlag=setBaudRate(port_num, BAUDRATE);

% Set initial parameters
global ADDR_OPERATING_MODE current_control_mode position_control_mode
global ADDR_CURRENT_LIMIT current_limit
global ADDR_POSITION_LIMIT_max ADDR_POSITION_LIMIT_min pos_lim_max pos_lim_min
global ADDR_MOVING_THRESHOLD moving_threshold

for i=1:length(IDs)
    DXL_ID=IDs(i);
    write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_MOVING_THRESHOLD, moving_threshold);
    if control_mode=="position"
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_OPERATING_MODE, position_control_mode);
        write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_POSITION_LIMIT_max, pos_lim_max);
        write4ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_POSITION_LIMIT_min, pos_lim_min);
    else
        write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_OPERATING_MODE, current_control_mode);
        write2ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_CURRENT_LIMIT, current_limit);
    end
end


% Activate torqie
global ADDR_TORQUE_ENABLE torque_enable
for i=1:length(IDs)
    DXL_ID=IDs(i);
    write1ByteTxRx(port_num, PROTOCOL_VERSION, DXL_ID, ADDR_TORQUE_ENABLE, torque_enable);
    dxl_comm_result = getLastTxRxResult(port_num, PROTOCOL_VERSION);
    dxl_error = getLastRxPacketError(port_num, PROTOCOL_VERSION);
    if dxl_comm_result ~= COMM_SUCCESS
        fprintf('%s\n', getTxRxResult(PROTOCOL_VERSION, dxl_comm_result));
    elseif dxl_error ~= 0
        fprintf('%s\n', getRxPacketError(PROTOCOL_VERSION, dxl_error));
    else
        fprintf('Dynamixel [ID:%d] has been successfully connected \n',DXL_ID);
    end
end

% Add the group read and group write for position
global ADDR_GOAL_POSITION ADDR_PRESENT_POSITION LEN_POSITION groupwrite_pos groupread_pos
groupwrite_pos=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_POSITION, LEN_POSITION);
groupread_pos = groupSyncRead(port_num, PROTOCOL_VERSION, ADDR_PRESENT_POSITION, LEN_POSITION);

for i=1:length(IDs)
    DXL_ID=IDs(i);
    dxl_addparam_result = groupSyncReadAddParam(groupread_pos, DXL_ID);
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncRead addparam for POSITION failed', DXL_ID);
        return;
    end    
end

% Add the group read and group write for current
global ADDR_GOAL_CURRENT ADDR_PRESENT_CURRENT LEN_CURRENT groupwrite_cur groupread_cur
groupwrite_cur=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_CURRENT, LEN_CURRENT);
groupread_cur = groupSyncRead(port_num, PROTOCOL_VERSION, ADDR_PRESENT_CURRENT, LEN_CURRENT);

for i=1:length(IDs)
    DXL_ID=IDs(i);
    dxl_addparam_result = groupSyncReadAddParam(groupread_cur, DXL_ID);
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncRead addparam for CURRENT failed', DXL_ID);
        return;
    end    
end
end