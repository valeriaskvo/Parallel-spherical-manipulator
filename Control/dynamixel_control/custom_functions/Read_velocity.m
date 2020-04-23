% Created by Valeria Skvo

function [velocity]=Read_velocity(IDs)
global ADDR_PRESENT_VELOCITY LEN_VELOCITY groupread_vel
[result]=Group_read(IDs,groupread_vel,ADDR_PRESENT_VELOCITY,LEN_VELOCITY,'VELOCITY');

if sum(isnan(result))==0
    result=double(result-(result>2^15)*2^16);
    velocity=result*(0.229*2*pi)/60;
else
    velocity=zeros(size(IDs))+nan;
end
end