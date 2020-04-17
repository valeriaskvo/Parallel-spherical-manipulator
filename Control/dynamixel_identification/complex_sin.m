function [x]=complex_sin(t,const)
n=length(const);
A=const(1:n/2);
w=const(n/2+1:n);
x=pi-A'*sin(w*t);
end