% Created by Valeria Skvo

function []=Write_position(IDs,pos)
global pos_lim_max pos_lim_min

variable=pos*2048/pi;
for i=1:length(variable)
   if variable(i)>pos_lim_max
       variable(i)=pos_lim_max;
   elseif variable(i)<pos_lim_min
       variable(i)=pos_lim_min;
   end 
end
variable=typecast(int16(variable),'uint16');

global LEN_POSITION groupwrite_pos

for i=1:length(IDs)
    DXL_ID=IDs(i);
    if length(variable)==1
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite_pos, DXL_ID, variable, LEN_POSITION);
    else
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite_pos, DXL_ID, variable(i), LEN_POSITION);
    end
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncWrite addparam for POSITION failed', DXL_ID);
        return;
    end
end
groupSyncWriteTxPacket(groupwrite_pos);
groupSyncWriteClearParam(groupwrite_pos);
end