close all;
clear all;

addpath(genpath('..\..\..\PSM git'));

Run_time=1800;
IDs=[11;12;13];
w=200;

dtype="dynamics";
load(sprintf("trajectories/trajectory_%s.mat",dtype))

% control_mode="position";
% 
% [portFlag,baudRateFlag]=Launch_dynamixel(IDs,control_mode);
% Set_initial_position(IDs,control_mode,pi)

% 
% files=zeros(size(IDs));
% for i=1:length(IDs)
%     DXL_ID=IDs(i);
%     files(i)=fopen(sprintf("ident_data/trajectory_%s_ID_%d.csv",dtype,DXL_ID),'w');
%     fprintf(files(i),'Time [sec],Position [rad],Current [A]\n'); 
% end
% 
% t=0;
% tic
% while t<Run_time
%     pos_set=complex_sin(t,const);
%     Write_position(IDs,pos_set,[]);
%     [position]=Read_position(IDs);
%     [current]=Read_current(IDs);
%     for i=1:length(IDs)
%        fprintf(files(i),'%.8f,%.8f,%.8f\n',t,position(i),current(i));  
%     end
%     t=toc;
% end
% toc
% 
% Close_dynamixel(IDs);
% for i=1:length(IDs)
%    fclose(files(i)); 
% end


results=readtable('trajectory_dynamics_ID_11.csv','PreserveVariableNames',true,'Delimiter', ',', 'HeaderLines', 0, 'ReadVariableNames', true,'Format','%.8f%.8f%.8f');
t=table2array(results(:,1));
dt=diff(t);

theta_set=zeros(size(t));
for i=1:length(t)
    theta_set(i)=complex_sin(t(i),const);
end
dtheta_set=[0;diff(theta_set)./dt];
ddtheta_set=[0;diff(theta_set)./dt];

for i=1:length(IDs)
    DXL_ID=IDs(i);
    results=readtable(sprintf("ident_data/trajectory_%s_ID_%d.csv",dtype,DXL_ID),'PreserveVariableNames',true,'Delimiter', ',', 'HeaderLines', 0, 'ReadVariableNames', true,'Format','%.8f%.8f%.8f');
    theta=table2array(results(:,2));
    dtheta=[0;diff(theta)./dt];
    ddtheta=[0;diff(dtheta)./dt];
    
    I=table2array(results(:,3));
    
    figure();
    sgtitle(sprintf("DXL ID: %d \n Trajectory function for %s model",DXL_ID,dtype))
    subplot(4,1,1)
    Plot_graphs(t,rad2deg([theta_set,theta]),'Time [sec]','Position [deg]',"",[0,300],[],["Measured value","Set value"],1)
    subplot(4,1,2)
    Plot_graphs(t,rad2deg([dtheta_set,dtheta]),'Time [sec]','Velocity [deg/sec]',"",[0,300],[],["Measured value","Set value"],1)
    subplot(4,1,3)
    Plot_graphs(t,rad2deg([ddtheta_set,ddtheta]),'Time [sec]','Acceleration [deg/sec^2]',"",[0,300],[],["Measured value","Set value"],1)
    subplot(4,1,4)
    Plot_graphs(t,I,'Time [sec]','Current [A]',"",[0,300],[],[],1)
%     save(sprintf("ident_data/trajectory_%s_ID_%d.mat",dtype,DXL_ID),'DXL_ID','t','theta','dtheta','ddtheta','I','k_dtheta')
end

% Plot_graphs(t(1:length(t)-1),1./dt,'Time [sec]','Frequency [Hz]',"Frequency of transmission of the control signal in time",[],[],[],0)