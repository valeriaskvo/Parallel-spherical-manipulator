% Created by Valeria Skvo

function []=Write_current(IDs,cur)
global current_limit

variable=cur/3.36e-3;
for i=1:length(variable)
   if variable(i)>current_limit
       variable(i)=current_limit;
   elseif variable(i)<-current_limit
       variable(i)=-current_limit;
   end 
end
global LEN_CURRENT groupwrite_cur
Group_write(IDs,groupwrite_cur,LEN_CURRENT,variable,'CURRENT')
end