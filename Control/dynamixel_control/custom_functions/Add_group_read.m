% Created by Valeria Skvo

function [groupread]=Add_group_read(IDs,port_num, PROTOCOL_VERSION, ADDR, LEN,name)
groupread=groupSyncRead(port_num, PROTOCOL_VERSION, ADDR, LEN);

for i=1:length(IDs)
    DXL_ID=IDs(i);
    dxl_addparam_result = groupSyncReadAddParam(groupread, DXL_ID);
    if dxl_addparam_result ~= true
        fprintf('[ID:%03d] groupSyncRead addparam for %s failed\n', DXL_ID,name);
        return;
    end    
end
end