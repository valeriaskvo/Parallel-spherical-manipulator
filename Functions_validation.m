close all;
clear all;

addpath(genpath('..\PSM git')); % Folder name

% Define a system parameters
beta_1=deg2rad(0);
beta_2=deg2rad(45);
alpha_1=deg2rad(90);
alpha_2=deg2rad(90);
system_radius=100;

system_parameters=[beta_1;
                   beta_2;
                   alpha_1;
                   alpha_2;
                   system_radius];

%% Validation inverse kinematics function
% Define the end-effector orientation by XYZ parametrization
phi_1=deg2rad(30);
phi_2=deg2rad(0);
phi_3=deg2rad(0);

phi_ee=[phi_1;
        phi_2;
        phi_3];

Visualization_PSM(system_parameters,phi_ee)
title("Correctness of the Inverse kinematic solution")

%% Validation forward kinematics function
angles=-pi/2+deg2rad(5):deg2rad(5):pi/2-deg2rad(5);
error_v1=zeros(length(angles),3);
error_v2=zeros(length(angles),3);

for i=1:length(angles)
    for j=1:3
        phi_zeros=[0;0;0];
        phi_zeros(j)=angles(i);
        error_v1(i,j)=Accuracy_checking_fk(phi_zeros,system_parameters,@Inverse_kinematics_v1_mex,@Forward_kinematics_v1_mex);
        error_v2(i,j)=Accuracy_checking_fk(phi_zeros,system_parameters,@Inverse_kinematics_v2_mex,@Forward_kinematics_v2_mex);
    end
end

Plot_graphs(rad2deg(angles'),error_v1,"\phi [deg]","Error of solution [deg^2]","Correctness of the FK solution for Lower joints control configuration",[-90 90],[-5000 max(max(error_v1))+5000],["Rotation around x-axis (\phi_1)","Rotation around y-axis (\phi_2)","Rotation around z-axis (\phi_3)"],0)
Plot_graphs(rad2deg(angles'),error_v2,"\phi [deg]","Error of solution [deg^2]","Correctness of the FK solution for Mid joints control configuration",[-90 90],[-5000 max(max(error_v2))+5000],["Rotation around x-axis (\phi_1)","Rotation around y-axis (\phi_2)","Rotation around z-axis (\phi_3)"],0)

%% Validation differential kinematics
dphi=[deg2rad(0.1); deg2rad(0.1); deg2rad(0.1)];

angles=-pi/2+deg2rad(5):deg2rad(5):pi/2-deg2rad(5);
error_v1=zeros(length(angles),3);
error_v2=zeros(length(angles),3);

for i=1:length(angles)
    for j=1:3
        phi_zeros=[0;0;0];
        phi_zeros(j)=angles(i);
        error_v1(i,j)=Accuracy_checking_J(phi_zeros,dphi,system_parameters,@Inverse_kinematics_v1_mex,@J_v1_mex);
        error_v2(i,j)=Accuracy_checking_J(phi_zeros,dphi,system_parameters,@Inverse_kinematics_v2_mex,@J_v2_mex);
    end
end

Plot_graphs(rad2deg(angles'),error_v1,"\phi [deg]","Error of solution [deg^2]","Correctness of the DK solution for Lower joints control configuration",[-90 90],[0 0.5],["Rotation around x-axis (\phi_1)","Rotation around y-axis (\phi_2)","Rotation around z-axis (\phi_3)"],0)
Plot_graphs(rad2deg(angles'),error_v2,"\phi [deg]","Error of solution [deg^2]","Correctness of the DK solution for Mid joints control configuration",[-90 90],[0 0.5],["Rotation around x-axis (\phi_1)","Rotation around y-axis (\phi_2)","Rotation around z-axis (\phi_3)"],0)



function [accuracy]=Accuracy_checking_fk(phi,system_parameters,inv_kin,for_kin)
q_v1=inv_kin(system_parameters,phi);
phi_calc=for_kin(system_parameters,q_v1);
phi_err=rad2deg(phi-phi_calc);
accuracy=phi_err'*phi_err;
end

function [accuracy]=Accuracy_checking_J(phi,dphi,system_parameters,inv_kin,jacob)
phi_0=phi-dphi;
q0=inv_kin(system_parameters,phi_0);
q=inv_kin(system_parameters,phi);
dq=q-q0;
J=jacob(system_parameters,phi);
dphi_calc=J*dq;
dphi_err=rad2deg(dphi-dphi_calc);
accuracy=dphi_err'*dphi_err;
end



