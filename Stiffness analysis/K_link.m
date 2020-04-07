function K=K_link(R,a,Ix,Iy,Iz,A)
E=2e9; %Young's modulus
nu=0.37; %Poisson's ratio
G=E/(2*(1+nu));

a1=a+sin(a)*cos(a);
a2=a-sin(a)*cos(a);
a3=3*a+sin(a)*cos(a)/2-4*sin(a);
a4=-sin(a)^2;
a5=1-cos(a)-sin(a)^2/2;
a6=sin(a)-a;
a7=cos(a)-1;
a8=2*sin(a)-a-sin(a)*cos(a);

K11=R/(2*A)*(a1/E+a2/G)+a3*R^3/(2*E*Iz);
K12=a4*R/(2*A)*(1/E-1/G)+a5*R^3/(2*E*Iz);
K16=a6*R^2/(E*Iz);
K22=R/(2*A)*(a1/G+a2/E)+a2*R^3/(2*E*Iz);
K25=a7*R^2/(E*Iz);
K33=R*a/(G*A)+R^3/2*(a3/(G*Ix)+a2/(E*Iy));
K34=R^2/2*(a2/(E*Iy)-a8/(E*Ix));
K35=R^2/2*(a5/(G*Ix)-a2/(E*Iy));
K44=R/2*(a1/(G*Ix)+a2/(E*Iy));
K45=a4*R/2*(1/(G*Ix)-1/(E*Iy));
K55=R/2*(a2/(G*Ix)+a1/(E*Iy));
K66=R*a/(E*Iz);

K=inv([K11,K12,0,0,0,K16;
       K12,K22,0,0,K25,0;
       0,0,K33,K34,K35,0;
       0,0,K34,K44,K45,0;
       0,K25,K35,K45,K55,0;
       K16,0,0,0,0,K66]);
end