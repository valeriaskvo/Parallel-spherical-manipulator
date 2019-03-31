function [theta,mu_1,mu_2]=Inverse_kinematics(i,beta_1,beta_2,alpha_1,alpha_2,phi_1,phi_2,phi_3,angle)
syms T;
% Parameters of system
eta_i=2*(i-1)*pi/3;

% Support vector
ex=[1;0;0];
ez=[0;0;1];

% Step 1: Find the theta angle
v_i=Rz(phi_1)*Ry(phi_2)*Rz(phi_3)*Q(-beta_2,eta_i)*ez;
w_i=Q(-(beta_1+pi),eta_i)*Q(alpha_1,angle)*ez;
equation=w_i'*v_i-cos(alpha_2);

[theta,have_solution]=Inverse_kinematic_solver(equation,angle);

if not(have_solution)
    theta=inf;
    mu_1=inf;
    mu_2=inf;
else
    % Step 2: Find the mu_1 angle
    v=Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta)*Q(alpha_2,angle)*ez;
    for k=1:3
        equation=v(k)-v_i(k);
        [mu_1,have_solution]=Inverse_kinematic_solver(equation,angle);
        if have_solution
            break
        end
    end
    
    if not(have_solution)
        mu_1=inf;
        mu_2=inf;        
    else
        % Step 3: find the mu_2 angle
        v_y_i=Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta)*Q(alpha_2,mu_1)*Q(0,angle)*ex;
        v_y=Rz(phi_1)*Ry(phi_2)*Rz(phi_3)*Q(-beta_2,eta_i)*ex;
        equation=v_y_i'*v_y-1;
        [mu_2,have_solution]=Inverse_kinematic_solver(equation,angle);
    end
end
end