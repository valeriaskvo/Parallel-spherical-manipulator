% Created by Valeria Skvo

function []=Write_velocity(IDs,vel)
global velocity_limit

variable=vel*60/(0.229*2*pi);
for i=1:length(variable)
   if variable(i)>velocity_limit
       variable(i)=velocity_limit;
   elseif variable(i)<-velocity_limit
       variable(i)=-velocity_limit;
   end 
end
global LEN_VELOCITY groupwrite_vel
disp(variable);
Group_write(IDs,groupwrite_vel,LEN_VELOCITY,variable,'VELOCITY')
end