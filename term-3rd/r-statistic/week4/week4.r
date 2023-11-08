task1 <- function() {
    sample <- seq(0, 15, by = 1)
    plot(sample, dhyper(sample, 25, 100, 15))
}

task2 <- function() {
    sample <- seq(5, 12, by = 1)
    print(sum(dhyper(sample, 25, 100, 15)))
}

task3 <- function() {
    curve(dexp(x, 0.6), 0, 10)
    curve(dexp(x, 0.3),0,10, add = TRUE, col = 'red')
}

task6 <- function() {
    par(mfrow = c(2, 1))
    x <- 0:50
    plot(x, dbinom(x, 50, 0.08), type = "h", ylim = c(0, 0.25))
    plot(x, dpois(x, 4), type = "h", ylim = c(0,0.25))
}

task7 <- function() {
    par(mfrow = c(1, 1))
    sample <- 0:50
    plot(sample, dbinom(sample, 50, 0.4), xlab = "x", ylab = "P(X=x)")
    curve(dnorm(x, 20,sqrt(12)), from = 0, to = 50, col = 'red', add = TRUE)
}

task7()