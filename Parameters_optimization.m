clear all;
syms angle real;
beta_1=0;
alpha=[15*pi/180];
for i=2:18
    alpha(i)=alpha(i-1)+15*pi/180;    
end

best_conf=0;
step_angle=30;
best_orientations=[];
best_parameters=[];
workspace_results=[];

iteration=1;
for i=1:18
    for j=1:18
        if (alpha(i)+alpha(j))>=pi/2
            break
        end
        beta_2=pi/2-alpha(i)-alpha(j);
        disp('alpha 1');
        disp(alpha(i));
        disp('alpha 2');
        disp(alpha(j));
        [n_conf,avalible_orientations]=Work_space(step_angle,alpha(i),alpha(j),beta_1,beta_2,iteration,angle);
        workspace_results(iteration,1)=alpha(i);
        workspace_results(iteration,2)=alpha(j);
        workspace_results(iteration,3)=n_conf;
        iteration=iteration+1;
        save('Workspace_analysis.mat', 'workspace_results', '-mat');
        if n_conf>best_conf
            best_conf=n_conf;
            best_orientations=avalible_orientations;
            save('Orientations.mat', 'avalible_orientations', '-mat');
            best_parameters=[alpha(i),alpha(j)];
            save('Optimization_result','best_parameters','-mat');
        end
    end
end
disp(best_parameters);