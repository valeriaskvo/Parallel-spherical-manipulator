close all;
clear all;

addpath(genpath('..\..\..\PSM git'));
k_dtheta=0.1;
t=60;

%% Finding trajectories for dynamics model
dtype="dynamics";
w=2*pi*linspace(0.1,1.5,2)';
A=1./w.^2;
const=[A;w];
opt_par=1:length(const);
[const,x,opt_val]=Optimal_trajectory_for_ident(t,opt_par,const,[],k_dtheta,dtype);
save(sprintf("trajectories/trajectory_%s.mat",dtype),'const','k_dtheta')

% %% Finding trajectories for energy model
% dtype="energy";
% w=2*pi*linspace(0.1,1.5,2)';
% A=1./w.^2;
% const=[A;w];
% opt_par=1:length(w);
% [const,x,opt_val]=Optimal_trajectory_for_ident(t,opt_par,const,[],k_dtheta,dtype);
% save(sprintf("trajectories/trajectory_%s.mat",dtype),'const','k_dtheta')

% dtype="energy";
% load(sprintf("trajectories/trajectory_%s.mat",dtype))
time=[300,1/50];
[traj,t]=trajectory_for_ident(time,const);
[Y,~]=generate_model_vectors(t,traj,zeros(size(traj(:,2))),dtype,k_dtheta,0);
[~,S,~]=svd(Y);

disp("Singular values of trajectory is:")
disp(S(1:3,1:3))
fprintf("Opt val: %.4f\n",(1-max([S(1,1),S(2,2),S(3,3)])/min([S(1,1),S(2,2),S(3,3)]))^2);

figure()
sgtitle(sprintf("Optimal generated trajectory function based on %s model\nFourier series with %d parameters",dtype,length(const)))
subplot(3,1,1)
Plot_graphs(t,traj(:,1),"t [sec]",'Position [rad]',[],[],[],[],1)
subplot(3,1,2)
Plot_graphs(t,traj(:,2),"t [sec]",'Velocity [rad/sec]',[],[],[],[],1)
subplot(3,1,3)
Plot_graphs(t,traj(:,3),"t [sec]",'Acceleration [rad^2/sec]',[],[],[],[],1)

function [const,traj,opt_val]=Optimal_trajectory_for_ident(t,opt_par,const,x0,k_dtheta,dtype)
if mod(length(const),2)==1
    disp('Invalid number of constant for complex sin trajectory');
    const=nan;
    traj=nan;
    dt=nan;
    return;
end

if isempty(opt_par)
    opt_par=1:length(const);
    opt_par=opt_par';        
end

if isempty(x0) || length(x0)~=length(opt_par)
    x0=rand(size(opt_par));
    x0(1)=1;
end

p_max=2*pi;
v_max=5.5;
a_max=32767*241.577*2*pi/60^2;
w=50;
dt=1/w;

limits=[p_max; v_max; a_max];
time=[t,dt];

options = optimoptions('fmincon','Display','iter','Algorithm','sqp');
[parameters_traj,f_val] = fmincon(@(x)cost_function(time,const,opt_par,x,k_dtheta,dtype),...
    x0,[],[],[],[],[],[],@(x)constr(time,const,opt_par,limits,x),options);

fprintf("The results for %s model\n",dtype)
fprintf("Optimal trajectory was finding with optimal value: %0.2f\n",f_val)

const(opt_par)=parameters_traj;
[traj,t]=trajectory_for_ident(time,const);
[Y,~]=generate_model_vectors(t,traj,zeros(size(traj(:,2))),dtype,k_dtheta,0);
[~,S,~]=svd(Y);

disp("Singular values of trajectory is:")
disp(S(1:3,1:3))

opt_val=[S(1,1),S(2,2),S(3,3)];

figure()
subplot(3,1,1)
Plot_graphs(t,rad2deg(traj(:,1)),"t [sec]",'Position [deg]',sprintf("Optimal generated trajectory function based on %s model\nFourier series with %d parameters",dtype,length(const)),[],[],[],1)
subplot(3,1,2)
Plot_graphs(t,rad2deg(traj(:,2)),"t [sec]",'Velocity [deg/sec]',[],[],[],[],1)
subplot(3,1,3)
Plot_graphs(t,rad2deg(traj(:,3)),"t [sec]",'Acceleration [deg^2/sec]',[],[],[],[],1)
end

function [cost]=cost_function(time,const,opt_par,x,k_dtheta,dtype)
const(opt_par)=x;
[traj,t]=trajectory_for_ident(time,const);

[Y,~]=generate_model_vectors(t,traj,zeros(size(traj(:,1))),dtype,k_dtheta,0);
[~,S,~]=svd(Y);

cost=(1-max([S(1,1),S(2,2),S(3,3)])/min([S(1,1),S(2,2),S(3,3)]))^2-(sum(const(1:length(const)/2)));
end

function [c,ceq] = constr(time,const,opt_par,limits,x)
const(opt_par)=x;
[traj]=trajectory_for_ident(time,const);
p_max=limits(1);
v_max=limits(2);
a_max=limits(3);

position_constr=[traj(:,1)-p_max;-traj(:,1)];
velocity_constr=[traj(:,2)-v_max;-traj(:,2)-v_max];
acceleration_constr=[traj(:,3)-a_max;-traj(:,3)-a_max];

c=[position_constr;velocity_constr;acceleration_constr];
ceq=[];
end

function [traj,t]=trajectory_for_ident(time,const)
dt=time(2);
t=0:dt:time(1);
x=zeros(size(t));
n=length(t);

for i=1:n
    x(i)=complex_sin(t(i),const);
end
dx=[0,diff(x)]/time(2);
ddx=[0,0,diff(x,2)]/time(2)^2;
t=t';
traj=[x',dx',ddx'];
end