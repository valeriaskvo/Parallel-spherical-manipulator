close all;
clear all;
addpath(genpath('..\..\..\PSM git'));

N=1000;
K_m=10.4e-3;
DXL_ID=11;
dtype="dynamics";
load(sprintf('ident_data/trajectory_dynamics_ID_%d.mat',DXL_ID));
state=[theta,dtheta,ddtheta];
t=t(1:N+100000);
[p,p_s,R,R_s,I_sim,time]=Find_parameters_dynamixel(N,t,state,I,dtype,k_dtheta,K_m);
% rho=10;
% gammas=[10,10,10];
% R=eye(N+1)*rho;
% Gamma=diag(gammas);
% 
% t=t(1:N+100000);
% 
% p_k=[0;0;0];
% p_s=zeros(length(t)-N,3);
% I_sim=zeros(length(t)-N,1);
% time=zeros(length(t)-N,1);
% for i=N+1:length(t)
%     time(i-N)=t(i);
%     [Y_k,tau_k]=generate_model_vectors(t(i-N:i),state(i-N:i,:),I(i-N:i),dtype,k_dtheta,K_m);
%     [p_k,I_calc]=fitting_parameters_SQP(Y_k,tau_k,p_k,Gamma,R);
%     p_s(i-N,:)=p_k';
%     I_sim(i-N)=I_calc;
% end
% 


figure()
sgtitle(sprintf("DXL ID: %d identification results for %s model",DXL_ID,dtype))

subplot(3,1,1)
Plot_graphs(time,p_s(:,1),'Time [sec]','J [kg*m^2]',[],[min(time) max(time)],[],[],1)
subplot(3,1,2)
Plot_graphs(time,p_s(:,2),'Time [sec]','b',[],[min(time) max(time)],[],[],1)
subplot(3,1,3)
Plot_graphs(time,p_s(:,3),'Time [sec]','\tau_f',[],[min(time) max(time)],[],[],1)

figure()
subplot(2,1,1)
Plot_graphs(time,I(N+1:N+length(time)),'Time [sec]','I [A]',"Real current",[min(time) max(time)],[],[],1)

subplot(2,1,2)
Plot_graphs(time,I_sim,'Time [sec]','I [A]',"Simulation current",[min(time) max(time)],[],[],1)

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


% IDs=[11];
% dtypes=["dynamics","energy"];
% for i=1:length(dtypes)
%     DXL_ID=IDs(1);
%     dtype=dtypes(i);
%     load(sprintf('ident_data/trajectory_dynamics_ID_%d.mat',DXL_ID));
%     [p,p_s,R,R_s,time]=Find_parameters_dynamixel_mex(N,t(1:round(length(t)/2)),dtheta,ddtheta,I,dtype,k_dtheta,K_m);
% 
%     figure()
%     sgtitle(sprintf("DXL ID: %d identification results for %s model",DXL_ID,dtype))
% 
%     subplot(3,1,1)
%     Plot_graphs(time,p_s(:,1),'Time [sec]','J [kg*m^2]',[],[min(time) max(time)],[],[],1)
%     subplot(3,1,2)
%     Plot_graphs(time,p_s(:,2),'Time [sec]','b',[],[min(time) max(time)],[],[],1)
%     subplot(3,1,3)
%     Plot_graphs(time,p_s(:,3),'Time [sec]','\tau_f',[],[min(time) max(time)],[],[],1)
% 
%     figure()
%     sgtitle(sprintf("DXL ID: %d changes of R=Y_k^TY_k for %s model",DXL_ID,dtype))
%     subplot(3,3,1)
%     Plot_graphs(time,R_s(:,1),'Time [sec]','R_{11} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,2)
%     Plot_graphs(time,R_s(:,2),'Time [sec]','R_{12} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,3)
%     Plot_graphs(time,R_s(:,3),'Time [sec]','R_{13} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,4)
%     Plot_graphs(time,R_s(:,4),'Time [sec]','R_{21} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,5)
%     Plot_graphs(time,R_s(:,5),'Time [sec]','R_{22} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,6)
%     Plot_graphs(time,R_s(:,6),'Time [sec]','R_{23} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,7)
%     Plot_graphs(time,R_s(:,7),'Time [sec]','R_{31} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,8)
%     Plot_graphs(time,R_s(:,8),'Time [sec]','R_{32} y.e.',[],[min(time) max(time)],[],[],1)
%     subplot(3,3,9)
%     Plot_graphs(time,R_s(:,9),'Time [sec]','R_{33} y.e.',[],[min(time) max(time)],[],[],1)
    
%     save(sprintf("ident_results/ID_%d.mat",DXL_ID),'DXL_ID','p','K_m','k_dtheta')
% end

