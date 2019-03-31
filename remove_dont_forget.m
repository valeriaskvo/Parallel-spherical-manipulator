clear all;
syms angle real;
R=Rz(pi/3)*Rx(pi/4)*Ry(pi/3);
lambda_r=[eye(5),zeros(5,1);
            zeros(1,6)];
lambda_p=[zeros(5,6);
    zeros(1,5), 1];
Rotation=[eye(3),zeros(3);
          zeros(3),R];
lambda1=Rotation*lambda_r
lambda2=Rotation*lambda_p