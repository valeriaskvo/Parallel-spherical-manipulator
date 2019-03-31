function K=K_link(R,a,Ix,Iy,Iz,A)
E=3000*10e6; %Young's modulus
nu=0.41; %Poisson's ratio
G=E/(2*(1+nu));

s1=a+sin(a)*cos(a);
s2=a-sin(a)*cos(a);
s3=3*a+sin(a)*cos(a)/2-4*sin(a);
s4=1-cos(a)-sin(a)^2/2;
s5=sin(a)-a;
s6=cos(a)-1;
s7=2*sin(a)-a-sin(a)*cos(a);
s8=-sin(a)^2;

c11=R/2*(s1/(G*Ix)+s2/(E*Iy));
c12=s8*R/2*(1/(G*Ix)-1/(E*Iy));
c16=R^2/2*(s2/(E*Iy)-s7/(E*Ix));
c22=R/2*(s2/(G*Ix)+s1/(E*Iy));
c26=R^2/2*(s4/(G*Ix)-s2/(E*Iy));
c33=R*a/(E*Iz);
c34=s5*R^2/(E*Iz);
c35=s6*R^2/(E*Iz);
c44=R/(2*A)*(s1/E+s2/G)+s3*R^3/(2*E*Iz);
c45=s8*R/(2*A)*(1/E-1/G)+s4*R^3/(2*E*Iz);
c55=R/(2*A)*(s1/G+s2/E)+s2*R^3/(2*E*Iz);
c66=R*a/(G*A)+R^3/2*(s3/(G*Ix)+s2/(E*Iy));

K=[c11,c12,0,0,0,c16;
   c12,c22,0,0,0,c26;
   0,0,c33,c34,c35,0;
   0,0,c34,c44,c45,0;
   0,0,c35,c45,c55,0;
   c16,c26,0,0,0,c66];
end