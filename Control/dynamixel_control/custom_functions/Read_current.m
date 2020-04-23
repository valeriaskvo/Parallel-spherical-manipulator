% Created by Valeria Skvo

function [current]=Read_current(IDs)
global ADDR_PRESENT_CURRENT LEN_CURRENT groupread_cur
[result]=Group_read(IDs,groupread_cur,ADDR_PRESENT_CURRENT,LEN_CURRENT,'CURRENT');

if sum(isnan(result))==0
    result=double(result-(result>2^15)*2^16);
    current=result*3.36e-3;
else
    current=zeros(size(IDs))+nan;
end
end