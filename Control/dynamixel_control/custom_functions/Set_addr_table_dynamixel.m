function []=Set_addr_table_dynamixel()
global BAUDRATE DEVICENAME PROTOCOL_VERSION COMM_SUCCESS COMM_TX_FAIL
BAUDRATE                 = 3e6;
DEVICENAME               = 'COM5';
PROTOCOL_VERSION         = 2.0;
COMM_SUCCESS             = 0;            % Communication Success result value
COMM_TX_FAIL             = -1001;        % Communication Tx Failed


global ADDR_TORQUE_ENABLE ADDR_OPERATING_MODE
ADDR_OPERATING_MODE     = 11;
ADDR_TORQUE_ENABLE      = 64;


end