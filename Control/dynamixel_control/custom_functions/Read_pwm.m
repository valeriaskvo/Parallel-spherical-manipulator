% Created by Valeria Skvo

function [pwm]=Read_pwm(IDs)
global ADDR_PRESENT_PWM LEN_PWM groupread_pwm
[result]=Group_read(IDs,groupread_pwm,ADDR_PRESENT_PWM,LEN_PWM,'PWM');

if sum(isnan(result))==0
    result=double(result-(result>2^15)*2^16);
    pwm=result/885*100;
else
    pwm=zeros(size(IDs))+nan;
end
end