function [theta,have_solution]=Inverse_kinematic_solver(equation,angle)
syms T;
have_solution=true;

equation=subs(equation,sin(angle),2*T/(1+T^2));
equation=subs(equation,cos(angle),(1-T^2)/(1+T^2))*(1+T^2);
equation=simplify(equation);
solution=solve(equation);
solution=double(solution);
n=size(solution);
if n(1)==1
    if or(solution^2>0,solution^2==0)
        theta=2*atan(solution);
    else
        theta=0;
        have_solution=false;
    end
elseif n(1)==0
    theta=inf;
    have_solution=false;
elseif or(solution(1)^2<0,solution(2)^2<0)
    theta=0;
    if not(or(solution(1)^2==0,solution(2)^2==0))
        have_solution=false;
    end
elseif abs(solution(1))==abs(solution(2))
    theta=2*atan(abs(solution(1)));
elseif abs(solution(1))<abs(solution(2))
    theta=2*atan(solution(1));
else
    theta=2*atan(solution(2));
end
end