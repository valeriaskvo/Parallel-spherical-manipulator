% Created by Valeria Skvo

function [position]=Read_position(IDs)
global ADDR_PRESENT_POSITION LEN_POSITION groupread_pos
[result]=Group_read(IDs,groupread_pos,ADDR_PRESENT_POSITION,LEN_POSITION,'POSITION');

if sum(isnan(result))==0
    position=double(result)/2048*pi;
else
    position=zeros(size(IDs))+nan;
end
end