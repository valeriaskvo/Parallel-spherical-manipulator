function D=D(d,phi_1,phi_2,phi_3,eta_i)
d_frame=Rz(phi_1)*Ry(phi_2)*Rz(phi_3)*Q(0,eta_i)*d;
D_scew=[0,-d_frame(3),d_frame(2);
        d_frame(3),0,-d_frame(1);
        -d_frame(2),d_frame(1),0];
D=[eye(3),D_scew';
    zeros(3,3),eye(3)];
end