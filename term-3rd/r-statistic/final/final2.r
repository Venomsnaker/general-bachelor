x <- seq(10, 22, 2)
y <- x - 3
z <- x + 3
df <- data.frame(x, y, z)
print(length(df))
plot(seq(-2, 2, 0.01), dnorm(seq(-2, 2, 0.01)))
