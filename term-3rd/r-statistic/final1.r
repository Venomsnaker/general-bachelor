print((3 != 4) || (4 >= 3))

perm <- function(n) {
  if (n == 1) {
    return(matrix(1))
  } else {
    sp <- perm(n - 1)
    p <- nrow(sp)
    a <- matrix(nrow = n * p, ncol = n)

    for (i in 1:n) {
      a[(i - 1) * p + 1:p, ] <- cbind(i, sp + (sp >= i))
    }
    return(a)
  }
}
print(perm(4))

print(sample(c(0, 1), 5, replace = TRUE))

# (3 + 4 + 5 + 4 + 3) => b = 19
# (1 * 3 + 2 * 4 + ...) / b => a = 3
# c = 3 (middle point)
x <- c(rep(1, 3), rep(2, 4), rep(3, 5), rep(4, 4), rep(5, 3))
print(mean(x))
print(length(x))
print(median(x))
print(3 * length(sample(1:6, 5)) + 10)
name <- c(
  " Pearson ", " Neymann ", " Fisher ",
  " Gosset ", " Bayes ", " Poisson "
)
birthday <- c(1857, 1894, 1890, 1876, 1702, 1781)

print(subset(name, birthday %% 25 > 13))
plot(0:9, dbinom(0:9, 9, 0.5), type = "h", ylab = "P(X = k)")

sample <- dpois(1000, lambda = 2)
print(pnorm(sample, mean = 2, sd = 1))

lambda <- uniroot(function(x) dpois(1, x) - 3 * dpois(0, x),
  interval = c(0, 10)
)$root
p_u_less_than_1 <- ppois(1, lambda * 100)
print(paste("Lambda: ", lambda))
print(paste("P(U<=1): ", p_u_less_than_1))
