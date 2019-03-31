function J=J(T,T_d,T_end,rotation)
Q_t=T*T_d;
if rotation
    Q_t=Q_t*T_end';
end
J=[Q_t(1,4);Q_t(2,4);Q_t(3,4);-Q_t(2,3);Q_t(3,3);-Q_t(3,2)];
end