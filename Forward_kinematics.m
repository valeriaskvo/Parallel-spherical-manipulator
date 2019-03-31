function [phi_1,phi_2,phi_3]=Forward_kinematics(i,beta_1,beta_2,alpha_1,alpha_2,theta,mu_1,mu_2)
eta_i=2*(i-1)*pi/3;
Q_transform=Q(-(beta_1+pi),eta_i)*Q(alpha_1,theta)*Q(alpha_2,mu_1)*Q(0,mu_2)*Q(-beta_2,eta_i)';
if or(Q_transform(3,3)==1,Q_transform(3,3)==-1)
    phi_1=atan2(Q_transform(2,1),Q_transform(1,1));
    phi_2=0;
    phi_3=0;
else
    phi_1=atan2(Q_transform(2,3),Q_transform(1,3));
    phi_2=atan2(sqrt(1-Q_transform(3,3)^2),Q_transform(3,3));
    phi_3=atan2(Q_transform(3,2),-Q_transform(3,1));
end
end