function l_r=lambda_r(R)
l_r=[eye(3),zeros(3,3);
     zeros(2,3),R(1:2,1:3)];
end
