function [result]=Group_read(IDs,groupread,ADDR,LEN,name)
result=zeros(size(IDs))+nan;
groupSyncReadTxRxPacket(groupread);

for i=1:length(IDs) 
    DXL_ID=IDs(i);
    dxl_getdata_result = groupSyncReadIsAvailable(groupread, DXL_ID, ADDR, LEN);
    if dxl_getdata_result ~= true
        fprintf('[ID:%02d] groupSyncRead getdata for %s failed\n', DXL_ID, name);
        return;
    end
    result(i)=groupSyncReadGetData(groupread, DXL_ID, ADDR, LEN);
end
end
