% Created by Valeria Skvo

function []=Dynamixel_mx106_inf()
global BAUDRATE DEVICENAME PROTOCOL_VERSION COMM_SUCCESS COMM_TX_FAIL
BAUDRATE                 = 3e6;
DEVICENAME               = 'COM5';
PROTOCOL_VERSION         = 2.0;
COMM_SUCCESS             = 0;            % Communication Success result value
COMM_TX_FAIL             = -1001;        % Communication Tx Failed

% Addr for inital parameters
global ADDR_TORQUE_ENABLE torque_enable torque_disable
ADDR_TORQUE_ENABLE      = 64;
torque_enable           = typecast(int16(1),'uint16');
torque_disable           = typecast(int16(0),'uint16');

global ADDR_OPERATING_MODE current_control_mode position_control_mode
ADDR_OPERATING_MODE     = 11;
current_control_mode    = typecast(int16(0),'uint16');
position_control_mode   = typecast(int16(4),'uint16');

global ADDR_CURRENT_LIMIT current_limit
ADDR_CURRENT_LIMIT      = 38;
current_limit           = int16(2047);

global ADDR_POSITION_LIMIT_max ADDR_POSITION_LIMIT_min pos_lim_max pos_lim_min
ADDR_POSITION_LIMIT_max = 48;
pos_lim_max             = int16(4096);
ADDR_POSITION_LIMIT_min = 52;
pos_lim_min             = int16(0);

global ADDR_MOVING_THRESHOLD moving_threshold
ADDR_MOVING_THRESHOLD   = 24;
moving_threshold        = typecast(int16(1),'uint16');

% Addr for position
global ADDR_GOAL_POSITION ADDR_PRESENT_POSITION LEN_POSITION
ADDR_GOAL_POSITION      = 116;
ADDR_PRESENT_POSITION   = 132;
LEN_POSITION            = 4;

% Addr for current
global ADDR_GOAL_CURRENT ADDR_PRESENT_CURRENT LEN_CURRENT
ADDR_GOAL_CURRENT       = 102;
ADDR_PRESENT_CURRENT    = 126;
LEN_CURRENT             = 2;

% Addr and other for time
global ADDR_REALTIME_TIC MAX_TIME T_INIT
ADDR_REALTIME_TIC       = 120;
MAX_TIME                = (2^15-1)*10^-3;
T_INIT                  = 0;
end