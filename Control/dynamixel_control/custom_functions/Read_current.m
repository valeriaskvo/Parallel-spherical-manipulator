% Created by Valeria Skvo

function [current]=Read_current(IDs)
result=zeros(size(IDs))+nan;

global ADDR_PRESENT_CURRENT LEN_CURRENT groupread_cur
groupSyncReadTxRxPacket(groupread_cur);

for i=1:length(IDs) 
    DXL_ID=IDs(i);
    dxl_getdata_result = groupSyncReadIsAvailable(groupread_cur, DXL_ID, ADDR_PRESENT_CURRENT, LEN_CURRENT);
    if dxl_getdata_result ~= true
        fprintf('[ID:%03d] groupSyncRead getdata for CURRENT failed', DXL_ID);
        current=zeros(size(IDs))+nan;
        return;
    end
    result(i)=groupSyncReadGetData(groupread_cur, DXL_ID, ADDR_PRESENT_CURRENT, LEN_CURRENT);
end

result=(result-(result>2^15)*2^16);
current=result*3.36e-3;
end