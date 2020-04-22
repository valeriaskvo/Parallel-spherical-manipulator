function [dxdt_state,t_now]=Get_state_vector(IDs,dxdt,t_init)
dxdt_state=zeros(3,length(IDs));
dxdt_state(1,:)=Read_position(IDs);
[dt,t_now]=Get_real_time(IDs,t_init);
if ~isempty(dxdt)
    dxdt_state(2,:)=(dxdt_state(1,:)-dxdt(1,:))/dt;
    dxdt_state(3,:)=(dxdt_state(2,:)-dxdt(2,:))/dt;
end
end