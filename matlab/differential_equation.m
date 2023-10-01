function sol = MySolveODE(a, b, c, x0, y0, dy0)
syms c1 c2 x;
D = b^2 - 4*a*c;
if D > 0
    r1 = (-b-sqrt(D))/2/a;
    r2 = (-b+sqrt(D))/2/a;
    sol = c1 * exp(r1*x) + c2 * exp(r2 * x);
else
    if D == 0
        r0 = -b/2/a;
        sol = (c1 + c2 * x) * exp(r0 * x);
    else
        alpha = -b/2/a;
        beta = sqrt(-D)/2/a;
        sol = exp(alpha*x)*(c1*cos(beta*x)+c2*sin(beta*x));
    end
end
eq1 = subs(sol,x,x0) - y0;
eq2 = subs(diff(sol,x),x,x0) - dy0;
cc = solve(eq1, eq2);
sol = subs(sol, c1, cc.c1);
sol = subs(sol, c2, cc.c2);
end

