close all;
clear all;
addpath(genpath('..\..\..\PSM git'));

N=1000;
K_m=10.4e-3;
dtype="dynamics";
IDs=[11;12;13];

for i=1:length(IDs)
    DXL_ID=IDs(i);
    load(sprintf('ident_data/trajectory_dynamics_ID_%d.mat',DXL_ID));
    [p,p_s,R,R_s,time]=Find_parameters_dynamixel_mex(N,t,dtheta,ddtheta,I,dtype,k_dtheta,K_m);

    figure()
    sgtitle(sprintf("DXL ID: %d identification results for %s model",DXL_ID,dtype))

    subplot(3,1,1)
    Plot_graphs(time,p_s(:,1),'Time [sec]','J [kg*m^2]',[],[min(time) max(time)],[],[],1)
    subplot(3,1,2)
    Plot_graphs(time,p_s(:,2),'Time [sec]','b',[],[min(time) max(time)],[],[],1)
    subplot(3,1,3)
    Plot_graphs(time,p_s(:,3),'Time [sec]','\tau_f',[],[min(time) max(time)],[],[],1)

    figure()
    sgtitle(sprintf("DXL ID: %d changes of R=Y_k^TY_k for %s model",DXL_ID,dtype))
    subplot(3,3,1)
    Plot_graphs(time,R_s(:,1),'Time [sec]','R_{11} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,2)
    Plot_graphs(time,R_s(:,2),'Time [sec]','R_{12} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,3)
    Plot_graphs(time,R_s(:,3),'Time [sec]','R_{13} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,4)
    Plot_graphs(time,R_s(:,4),'Time [sec]','R_{21} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,5)
    Plot_graphs(time,R_s(:,5),'Time [sec]','R_{22} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,6)
    Plot_graphs(time,R_s(:,6),'Time [sec]','R_{23} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,7)
    Plot_graphs(time,R_s(:,7),'Time [sec]','R_{31} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,8)
    Plot_graphs(time,R_s(:,8),'Time [sec]','R_{32} y.e.',[],[min(time) max(time)],[],[],1)
    subplot(3,3,9)
    Plot_graphs(time,R_s(:,9),'Time [sec]','R_{33} y.e.',[],[min(time) max(time)],[],[],1)
    
    save(sprintf("ident_results/ID_%d.mat",DXL_ID),'DXL_ID','p','K_m','k_dtheta')
end

