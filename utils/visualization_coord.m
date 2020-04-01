function [O]=visualization_coord(H,system_radius)
[coord_system,O]=new_coordinate_system(H,system_radius);
scatter3(O(1),O(2),O(3),'k')
color=['r','g','b'];
for j=1:3
    X=coord_system(:,j);
    A=X-O;
    quiver3(O(1),O(2),O(3),A(1),A(2),A(3),color(j))    
end
end

function [coord_system,O]=new_coordinate_system(H,system_radius)
coord_system=zeros(3,3);
O=zeros(3,1);
ex=[system_radius/5;0;0;1];
ey=[0;system_radius/5;0;1];
ez=[0;0;system_radius/5;1];
x_axis=H*ex;
y_axis=H*ey;
z_axis=H*ez;
coord_system(:,1)=x_axis(1:3);
coord_system(:,2)=y_axis(1:3);
coord_system(:,3)=z_axis(1:3);
O=H(1:3,4);
end