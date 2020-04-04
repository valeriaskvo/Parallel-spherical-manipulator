function []=Workspace_visualization(phi_set,cartesian_space,workspace)
phi_set=rad2deg(phi_set);
figure()
scatter3(phi_set(workspace==0,1),phi_set(workspace==0,2),phi_set(workspace==0,3),'g')
hold on
scatter3(phi_set(workspace==1,1),phi_set(workspace==1,2),phi_set(workspace==1,3),'c')
scatter3(phi_set(workspace==2,1),phi_set(workspace==2,2),phi_set(workspace==2,3),'b')
scatter3(phi_set(workspace==3,1),phi_set(workspace==3,2),phi_set(workspace==3,3),'r')
legend('Workspace point', 'Serial singularity', 'Parallel singularity','Collision')
title('Robot workspace in XYZ Euler angles orientation space')
axis equal
xlabel('\phi_1 [deg]')
ylabel('\phi_2 [deg]')
zlabel('\phi_3 [deg]')

figure()
scatter3(cartesian_space(workspace==0,1),cartesian_space(workspace==0,2),cartesian_space(workspace==0,3),'g')
hold on
scatter3(cartesian_space(workspace==1,1),cartesian_space(workspace==1,2),cartesian_space(workspace==1,3),'c')
scatter3(cartesian_space(workspace==2,1),cartesian_space(workspace==2,2),cartesian_space(workspace==2,3),'b')
scatter3(cartesian_space(workspace==3,1),cartesian_space(workspace==3,2),cartesian_space(workspace==3,3),'r')
legend('Workspace point', 'Serial singularity', 'Parallel singularity','Collision')
title('Robot workspace in cartesian space')
xlabel('x')
ylabel('y')
zlabel('z')
end