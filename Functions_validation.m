close all;
clear all;

addpath(genpath('..\PSM git')); % Folder name

beta_1=deg2rad(0);
beta_2=deg2rad(90);
alpha_1=deg2rad(90);
alpha_2=deg2rad(90);

phi_1=deg2rad(0);
phi_2=deg2rad(0);
phi_3=deg2rad(0);

i=3;
eta_i=(i-1)*2*pi/3;

Visualization_PSM(beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,10)