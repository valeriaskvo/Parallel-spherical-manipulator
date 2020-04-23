% Created by Valeria Skvo

function []=Write_position(IDs,pos,vel)
global pos_lim_max pos_lim_min

variable=(pos+2*pi)*2048/pi;
for i=1:length(variable)
   if variable(i)>pos_lim_max
       variable(i)=pos_lim_max;
   elseif variable(i)<pos_lim_min
       variable(i)=pos_lim_min;
   end 
end
global LEN_PROFILE_VELOCITY non_control_velocity groupwrite_profile_vel
if ~isempty(vel)
    velocity=60*vel/(0.229*2*pi);
else
    velocity=non_control_velocity;
end

global LEN_POSITION groupwrite_pos

Group_write(IDs,groupwrite_pos,LEN_POSITION,variable,'POSITION')
Group_write(IDs,groupwrite_profile_vel,LEN_PROFILE_VELOCITY,velocity,'PROFILE VELOCITY')

end