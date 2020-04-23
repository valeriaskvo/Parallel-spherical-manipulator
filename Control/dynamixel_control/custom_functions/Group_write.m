function []=Group_write(IDs,groupwrite,LEN,variable,name)
variable=typecast(int16(variable),'uint16');
disp(variable)
for i=1:length(IDs)
    DXL_ID=IDs(i);
    if length(variable)==1
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite, DXL_ID, variable, LEN);
    else
        dxl_addparam_result=groupSyncWriteAddParam(groupwrite, DXL_ID, variable(i), LEN);
    end
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncWrite addparam for %s failed\n', DXL_ID,name);
        return;
    end
end
groupSyncWriteTxPacket(groupwrite);
groupSyncWriteClearParam(groupwrite);
end