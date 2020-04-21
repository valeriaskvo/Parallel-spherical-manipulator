function [Y_k,tau_k]=generate_model_vectors(time,dtheta,ddtheta,I,dtype,k_dtheta,K_m)
if dtype=="energy"
    Y_k=[1/2*dtheta.^2,cumtrapz(time,dtheta.^2),cumtrapz(time,dtheta.*tanh(dtheta./k_dtheta))];
    tau_k=I.*dtheta*K_m;
elseif dtype=="dynamics"
    Y_k=[ddtheta,dtheta,tanh(dtheta./k_dtheta)];
    tau_k=I*K_m;    
else
    Y_k=nan;
    tau_k=nan;
    disp("Incorrect model type")
end
end