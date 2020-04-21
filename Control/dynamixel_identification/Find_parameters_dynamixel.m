function [p,p_s,R,R_s,time]=Find_parameters_dynamixel(N,t,dtheta,ddtheta,I,dtype,k_dtheta,K_m)
R=zeros(3,3);
R_s=zeros(length(t)-N,9);
time=zeros(length(t)-N,1);
for i=N+1:length(t)
    [Y_k,~]=generate_model_vectors(t(i-N:i),dtheta(i-N:i),ddtheta(i-N:i),I(i-N:i),dtype,k_dtheta,K_m);
    R_i=Y_k'*Y_k;
    R_s(i-N,:)=[R_i(1,:),R_i(2,:),R_i(3,:)];
    R=R+R_i;
    time(i-N)=t(i);
end
R=R./(length(time));

p_k=[0;0;0];
p_s=zeros(length(t)-N,3);
for i=N+1:length(t)
   [Y_k,tau_k]=generate_model_vectors(t(i-N:i),dtheta(i-N:i),ddtheta(i-N:i),I(i-N:i),dtype,k_dtheta,K_m);
   x_k=inv(Y_k'*Y_k)*Y_k'*tau_k;
   p_k=p_k+R*Y_k'*(tau_k-Y_k*x_k);
   p_s(i-N,:)=p_k';
end
p=p_k;
end