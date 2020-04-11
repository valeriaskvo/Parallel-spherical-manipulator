clear all;
close all;

beta_1=deg2rad(0);
beta_2=deg2rad(90);
alpha_1=deg2rad(90);
alpha_2=deg2rad(90);
system_radius=150*10^-3;

system_parameters=[beta_1;
                   beta_2;
                   alpha_1;
                   alpha_2;
                   system_radius];
               
phi_1=deg2rad(0);
phi_2=deg2rad(0);
phi_3=deg2rad(0);

phi_ee=[phi_1;
        phi_2;
        phi_3];

th_link=10*10^(-3);             % m (link thickness)
A=th_link^2;                    % m^2 (cross-sectional area of link)
K_act=10^6;                     % N/rad (actuator stiffness)

% Moment of Inertia at Origin for link 1 (g mm^2)
Ixx1 = 4607.684;
Iyy1 = 2.829E+04;
Izz1 = 3.272E+04;

I1=[Ixx1, Iyy1, Izz1]*1E-9;    % kg*m^2

% Moment of Inertia at Origin for link 2 (g mm^2)
Ixx2 = 4607.684;
Iyy2 = 2.829E+04;
Izz2 = 3.272E+04;
I2=[Ixx2, Iyy2, Izz2]*1E-9;    % kg*m^2           

K_l1=K_link(system_radius,alpha_1,I1(1),I1(2),I1(3),A);
K_l2=K_link(system_radius,alpha_2,I2(1),I2(2),I2(3),A);

step=deg2rad(5);

angles=-pi/2+step:step:pi/2-step;

[phi_1,phi_2]=meshgrid(angles',angles');
res_MSA=zeros(size(phi_1,1),size(phi_1,1),6);

F=[0;-30;0;0;0;0];

for i=1:size(phi_1,1)
    for j=1:size(phi_1,2)
        phi_ee=[phi_1(i,j);phi_2(i,j);0];
        Kc_msa=MSA(system_parameters,phi_ee,K_l1,K_l2,K_act);
        dx_msa=inv(Kc_msa)*F;
        res_MSA(i,j,:)=dx_msa;
    end
end
titles=[" x component"," y component"," z component"," \alpha_x component"," \alpha_y component"," \alpha_z component"];

for i=1:6
    deflection_map_vis(phi_1,phi_2,res_MSA(:,:,i),"Deflection map for"+titles(i))
    max_val=max(max(res_MSA(:,:,i)));
    min_val=min(min(res_MSA(:,:,i)));
    if i<4
       fprintf("Max deflection for%s: %.4f [mm]; Min deflection: %.4f [mm]\n",titles(i),max_val*10^3,min_val*10^3)
    else
       fprintf("Max deflection for%s: %.4f [deg]; Min deflection: %.4f [deg]\n",titles(i),rad2deg(max_val),rad2deg(min_val))
    end
end

function []=deflection_map_vis(X,Y,Z,title_name)
figure()
contourf(rad2deg(X),rad2deg(Y),Z)
xlabel('\phi_1 [deg]')
ylabel('\phi_2 [deg]')
grid on
title(title_name)
end