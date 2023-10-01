syms x y
f(x,y) = exp(x * y)
g(x,y) = diff(diff(f(x,y), y, 6), x, 2)
g(1,1)

syms x y t
f(x,y) = int( exp(-t^2), t, x, x + y)
g(x,y) = diff(f(x,y), y, 1)
g(1,1)