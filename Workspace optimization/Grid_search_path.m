% Created by Valeria Skvo

function [phi_set,cartesian_space]=Grid_search_path(step)
phi_1=-pi/2:step:pi/2;
phi_2=-pi/2:step:pi/2;
phi_3=0:step:2*pi;

[x,y,z]=meshgrid(phi_1,phi_2,phi_3);
phi_set=[reshape(x,[],1),reshape(y,[],1),reshape(z,[],1)];
cartesian_space=zeros(size(phi_set));
for i=1:length(phi_set)
    z_vect=Rx(phi_set(i,1))*Ry(phi_set(i,2))*Rz(phi_set(i,3))*[0;0;1];
    cartesian_space(i,:)=z_vect';
end
end