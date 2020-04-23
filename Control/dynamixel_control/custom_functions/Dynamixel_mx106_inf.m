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
torque_disable          = typecast(int16(0),'uint16');

global ADDR_RETURN_DELAY_TIME DELAY_TIME
ADDR_RETURN_DELAY_TIME  = 9;
DELAY_TIME              = typecast(int16(0),'uint16');

% Operating modes
global ADDR_OPERATING_MODE current_control_mode pwm_control_mode position_control_mode velocity_control_mode
ADDR_OPERATING_MODE     = 11;
current_control_mode    = typecast(int16(0),'uint16');
pwm_control_mode        = typecast(int16(16),'uint16');
position_control_mode   = typecast(int16(4),'uint16');
velocity_control_mode   = typecast(int16(1),'uint16');

% Limits
global ADDR_CURRENT_LIMIT current_limit
ADDR_CURRENT_LIMIT      = 38;
current_limit           = int16(2047);

global ADDR_PWM_LIMIT pwm_limit
ADDR_PWM_LIMIT          = 36;
pwm_limit               = int16(885);

global ADDR_POSITION_LIMIT_max ADDR_POSITION_LIMIT_min pos_lim_max pos_lim_min
ADDR_POSITION_LIMIT_max = 48;
pos_lim_max             = int16(4096);
ADDR_POSITION_LIMIT_min = 52;
pos_lim_min             = int16(0);

global ADDR_VELOCITY_LIMIT velocity_limit
ADDR_VELOCITY_LIMIT     = 44;
velocity_limit          = int16(250);

global ADDR_MOVING_THRESHOLD moving_threshold
ADDR_MOVING_THRESHOLD   = 24;
moving_threshold        = typecast(int16(1),'uint16');

% Addr for current control
global ADDR_GOAL_CURRENT ADDR_PRESENT_CURRENT LEN_CURRENT
ADDR_GOAL_CURRENT       = 102;
ADDR_PRESENT_CURRENT    = 126;
LEN_CURRENT             = 2;

% Addr for pwm control
global ADDR_GOAL_PWM ADDR_PRESENT_PWM LEN_PWM
ADDR_GOAL_PWM           = 100;
ADDR_PRESENT_PWM        = 124;
LEN_PWM                 = 2;

% Addr for position control
global ADDR_GOAL_POSITION ADDR_PRESENT_POSITION LEN_POSITION
ADDR_GOAL_POSITION      = 116;
ADDR_PRESENT_POSITION   = 132;
LEN_POSITION            = 4;

global ADDR_PROFILE_VELOCITY LEN_PROFILE_VELOCITY non_control_velocity
ADDR_PROFILE_VELOCITY   = 112;
non_control_velocity    = typecast(int16(0),'uint16');
LEN_PROFILE_VELOCITY    = 4;

% Addr for velocity control
global ADDR_GOAL_VELOCITY ADDR_PRESENT_VELOCITY LEN_VELOCITY
ADDR_GOAL_VELOCITY      = 104;
ADDR_PRESENT_VELOCITY   = 128;
LEN_VELOCITY            = 4;

% Addr and other for time
global ADDR_REALTIME_TIC MAX_TIME T_INIT
ADDR_REALTIME_TIC       = 120;
MAX_TIME                = (2^15-1)*10^-3;
T_INIT                  = 0;
end