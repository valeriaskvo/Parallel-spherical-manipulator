function T=Trans_d(x,y,z)
T=eye(4);
if x
    T(1,4)=1;
elseif y
    T(2,4)=1;
elseif z
    T(3,4)=1;
end
end