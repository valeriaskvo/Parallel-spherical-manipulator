function [n_conf,avalible_orientations]=Work_space(step_angle,alpha_1,alpha_2,beta_1,beta_2,iter,angle)
phi_arr=[0];
phi=0;
n_iterations=1;
while phi<2*pi
    phi=phi+step_angle*pi/180;
    n_iterations=n_iterations+1;
    phi_arr(n_iterations)=phi;
end
avalible_orientations=[];
n_conf=1;
for n=1:n_iterations
    disp([iter,n,alpha_1,alpha_2]);
    for j=1:n_iterations
        if and(phi_arr(j)<pi/2,phi_arr(j)>3*pi/2)
            break;
        end
        for k=1:n_iterations
            have_solutions=true;
            for i=1:3
                [theta,mu_1,mu_2]=Inverse_kinematics(i,beta_1,beta_2,alpha_1,alpha_2,phi_arr(n),phi_arr(j),phi_arr(k),angle);
                if theta==inf || mu_1==inf || mu_2==inf
                    have_solutions=false;
                    break
                end
            end
            if have_solutions
                avalible_orientations(n_conf,1)=phi_arr(n);
                avalible_orientations(n_conf,2)=phi_arr(j);
                avalible_orientations(n_conf,3)=phi_arr(k);
                n_conf=n_conf+1;
                break
            end
        end
    end
end
end