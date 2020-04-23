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
global ADDR_RETURN_DELAY_TIME DELAY_TIME
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_RETURN_DELAY_TIME, 1);
Group_write(IDs,groupwrite,1,DELAY_TIME,"DELAY TIME");
clear groupwrite ADDR_RETURN_DELAY_TIME DELAY_TIME;

Change_contol_mode(IDs,control_mode)

% Set limits
global ADDR_CURRENT_LIMIT current_limit LEN_CURRENT
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_CURRENT_LIMIT, LEN_CURRENT);
Group_write(IDs,groupwrite,LEN_CURRENT,current_limit,"CURRENT LIMIT");
clear groupwrite ADDR_CURRENT_LIMIT;

global ADDR_PWM_LIMIT pwm_limit LEN_PWM
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_PWM_LIMIT, LEN_PWM);
Group_write(IDs,groupwrite,LEN_PWM,pwm_limit,"PWM LIMIT");
clear groupwrite ADDR_PWM_LIMIT;

global ADDR_POSITION_LIMIT_max ADDR_POSITION_LIMIT_min pos_lim_max pos_lim_min LEN_POSITION
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_POSITION_LIMIT_max, LEN_POSITION);
Group_write(IDs,groupwrite,LEN_POSITION,pos_lim_max,"POSITION LIMIT");
clear groupwrite ADDR_POSITION_LIMIT_max;
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_POSITION_LIMIT_min, LEN_POSITION);
Group_write(IDs,groupwrite,LEN_POSITION,pos_lim_min,"POSITION LIMIT");
clear groupwrite ADDR_POSITION_LIMIT_min;

global ADDR_VELOCITY_LIMIT velocity_limit LEN_VELOCITY
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_VELOCITY_LIMIT, LEN_VELOCITY);
Group_write(IDs,groupwrite,LEN_VELOCITY,velocity_limit,"VELOCITY LIMIT");
clear groupwrite ADDR_VELOCITY_LIMIT;

global ADDR_MOVING_THRESHOLD moving_threshold
groupwrite=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_MOVING_THRESHOLD, 4);
Group_write(IDs,groupwrite,4,moving_threshold,"MOVING THRESHOLD");
clear groupwrite ADDR_MOVING_THRESHOLD moving_threshold;

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

% Add the group read and group write for current
global ADDR_GOAL_CURRENT ADDR_PRESENT_CURRENT groupwrite_cur groupread_cur
groupwrite_cur=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_CURRENT, LEN_CURRENT);
groupread_cur=Add_group_read(IDs,port_num, PROTOCOL_VERSION, ADDR_PRESENT_CURRENT, LEN_CURRENT,'CURRENT');

% Add the group read and group wrint for pwm
global ADDR_GOAL_PWM ADDR_PRESENT_PWM groupwrite_pwm groupread_pwm
groupwrite_pwm=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_PWM, LEN_PWM);
groupread_pwm=Add_group_read(IDs,port_num, PROTOCOL_VERSION, ADDR_PRESENT_PWM, LEN_PWM,'PWM'); 

% Add the group read and group write for position
global ADDR_GOAL_POSITION ADDR_PRESENT_POSITION groupwrite_pos groupread_pos
groupwrite_pos=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_POSITION, LEN_POSITION);
groupread_pos=Add_group_read(IDs,port_num, PROTOCOL_VERSION, ADDR_PRESENT_POSITION, LEN_POSITION,'POSITION'); 

global ADDR_PROFILE_VELOCITY LEN_PROFILE_VELOCITY non_control_velocity groupwrite_profile_vel
groupwrite_profile_vel=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_PROFILE_VELOCITY, LEN_PROFILE_VELOCITY);
Group_write(IDs,groupwrite_profile_vel,LEN_PROFILE_VELOCITY,non_control_velocity,'PROFILE VELOCITY');

% Addr the group read and group write for velocity
global ADDR_GOAL_VELOCITY ADDR_PRESENT_VELOCITY groupwrite_vel groupread_vel
groupwrite_vel=groupSyncWrite(port_num, PROTOCOL_VERSION, ADDR_GOAL_VELOCITY, LEN_VELOCITY);
groupread_vel=Add_group_read(IDs,port_num, PROTOCOL_VERSION, ADDR_PRESENT_VELOCITY, LEN_VELOCITY,'VELOCITY'); 
end