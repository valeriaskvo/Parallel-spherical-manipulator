% Created by Valeria Skvo

function []=Write_pwm(IDs,pwm)
global pwm_limit

variable=pwm*885/100;
for i=1:length(variable)
   if variable(i)>pwm_limit
       variable(i)=pwm_limit;
   elseif variable(i)<-pwm_limit
       variable(i)=-pwm_limit;
   end 
end
global LEN_PWM groupwrite_pwm
Group_write(IDs,groupwrite_pwm,LEN_PWM,variable,'PWM')
end