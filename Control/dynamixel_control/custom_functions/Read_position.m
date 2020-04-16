% Created by Valeria Skvo

function [position]=Read_position(IDs)
result=zeros(size(IDs))+nan;

global ADDR_PRESENT_POSITION LEN_POSITION groupread_pos
groupSyncReadTxRxPacket(groupread_pos);

for i=1:length(IDs) 
    DXL_ID=IDs(i);
    dxl_getdata_result = groupSyncReadIsAvailable(groupread_pos, DXL_ID, ADDR_PRESENT_POSITION, LEN_POSITION);
    if dxl_getdata_result ~= true
        fprintf('[ID:%03d] groupSyncRead getdata for POSITION failed', DXL_ID);
        position=zeros(size(IDs))+nan;
        return;
    end
    result(i)=groupSyncReadGetData(groupread_pos, DXL_ID, ADDR_PRESENT_POSITION, LEN_POSITION);
end

position=double(result)/2048*pi;
end