function K_global=K_global(r,alpha,K,R)
L=[0,0,0;
    0,0,-2*r*sin(alpha/2);
    2*r*sin(alpha/2),0,0];
K_22=K;
K_12=-[eye(3),zeros(3,3);L,eye(3,3)]*K_22;
K_11=[Rz(pi),zeros(3,3);zeros(3,3),Rz(pi)]'*K_22*[Rz(pi),zeros(3,3);zeros(3,3),Rz(pi)];
K_21=-[eye(3),zeros(3,3);L,eye(3,3)]*K_11;
R_global=[R,zeros(3,3),zeros(3,3),zeros(3,3);
          zeros(3,3),R,zeros(3,3),zeros(3,3);
          zeros(3,3),zeros(3,3),R,zeros(3,3);
          zeros(3,3),zeros(3,3),zeros(3,3),R];
K_global=R_global*[K_11,K_12;K_21,K_22]*R_global';

end