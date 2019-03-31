function R_T=R_T(R)
R_T=eye(4);
for i=1:3
    for j=1:3
        R_T(i,j)=R(i,j);
    end
end
end
