close all;
clear all;

addpath(genpath('..\..\..\PSM git'));

Run_time=10;
IDs=[11;12;13];
control_mode="position";

% [portFlag,baudRateFlag]=Launch_dynamixel(IDs,control_mode);
% Set_initial_position(IDs,control_mode,pi)
% 
% dtype="dynamics";
% load(sprintf("trajectories/trajectory_%s.mat",dtype))
% [~,t_init]=Get_real_time(IDs,0,0);
% t=0;
% 
% time=[];
% pos_sets=[];
% positions=[];
% currents=[];
% tic
% while t<Run_time
%     pos_set=complex_sin(t,const);
%     Write_position(IDs,pos_set);
%     [position]=Read_position(IDs);
%     [current]=Read_current(IDs);
%     time=[time;t];
%     pos_sets=[pos_sets;pos_set];
%     positions=[positions;position'];
%     currents=[currents;current'];
%     [t,t_init]=Get_real_time(IDs,t,t_init);
% end
% toc
% 
% Close_dynamixel(IDs);
% 
% t=time;
% dt=diff(t);
% theta_set=pos_sets;
% dtheta_set=[0;diff(theta_set)./dt];
% ddtheta_set=[0;diff(theta_set)./dt];
% 
% for i=1:length(IDs)
%     DXL_ID=IDs(i);
%     theta=positions(:,i);
%     dtheta=[0;diff(theta)./dt];
%     ddtheta=[0;diff(dtheta)./dt];
%     
%     I=currents(:,i);
%     
%     figure();
%     subplot(4,1,1)
%     Plot_graphs(time,rad2deg([theta_set,theta]),'Time [sec]','Position [deg]',sprintf("DXL ID: %d \n Trajectory function for %s model",DXL_ID,dtype),[],[],["Measured value","Set value"],1)
%     subplot(4,1,2)
%     Plot_graphs(time,rad2deg([dtheta_set,dtheta]),'Time [sec]','Velocity [deg/sec]',"",[],[],["Measured value","Set value"],1)
%     subplot(4,1,3)
%     Plot_graphs(time,rad2deg([ddtheta_set,ddtheta]),'Time [sec]','Acceleration [deg/sec^2]',"",[],[],["Measured value","Set value"],1)
%     subplot(4,1,4)
%     Plot_graphs(time,I,'Time [sec]','Current [A]',"",[],[],[],1)
%     save(sprintf("ident_data/trajectory_%s_ID_%d.mat",dtype,DXL_ID),'DXL_ID','t','theta','dtheta','ddtheta','I','k_dtheta')
% end
% 
% Plot_graphs(time(1:length(time)-1),1./dt,'Time [sec]','Frequency [Hz]',"Frequency of transmission of the control signal in time",[],[],[],0)
% 
