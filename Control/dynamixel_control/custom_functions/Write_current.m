% Created by Valeria Skvo

function []=Write_current(IDs,cur)
global current_limit

variable=cur/3.36e-3;
for i=1:length(variable)
   if variable(i)>current_limit
       variable(i)=current_limit;
   elseif variable(i)<-current_limit
       variable(i)=-current_limit;
   end 
end
variable=typecast(int16(variable),'uint16');
global LEN_CURRENT groupwrite_cur

for i=1:length(IDs)
    DXL_ID=IDs(i);
    if length(variable)==1
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite_cur, DXL_ID, variable, LEN_CURRENT);
    else
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite_cur, DXL_ID, variable(i), LEN_CURRENT);
    end
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncWrite addparam for CURRENT failed', DXL_ID);
        return;
    end
end
groupSyncWriteTxPacket(groupwrite_cur);
groupSyncWriteClearParam(groupwrite_cur);
end