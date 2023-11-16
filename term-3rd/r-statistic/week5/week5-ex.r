task1 <- function() {
    mu <- 1
    sigma <- 1
    lbd <- 1
    n1 <- 100
    n2 <- 10000
    n3 <- 100000
    m <- 1000

    Z <- function(n) {
        x <- rpois(n, lbd)
        sqrt(n) * (mean(x) - mu) / sigma
    }

    vecZ1 <- function(m) replicate(m, Z(n1))
    hist(vecZ1(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)

    vecZ2 <- function(m) replicate(m, Z(n2))
    hist(vecZ2(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)

    vecZ3 <- function(m) replicate(m, Z(n3))
    hist(vecZ3(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)
}

task2 <- function() {
    mu <- 0.5
    sigma <- 0.25
    n1 <- 100
    n2 <- 10000
    n3 <- 100000
    m <- 1000

    Z <- function(n) {
        x <- runif(n, 0, 1)
        sqrt(n) * (mean(x) - mu) / sigma
    }

    vecZ4 <- function(m) replicate(m, Z(n1))
    hist(vecZ4(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)

    vecZ5 <- function(m) replicate(m, Z(n2))
    hist(vecZ5(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)

    vecZ6 <- function(m) replicate(m, Z(n3))
    hist(vecZ6(m), freq = 0, breaks = 40)
    curve(dnorm(x), col = "blue", add = T)
}

task3 <- function() {
    n <- 2
    m1 <- 100
    m2 <- 1000
    m3 <- 10000

    Z <- function() {
        x1 <- rnorm(2, 0, 1)
        x2 <- rnorm(2, 0, 1)
        x1^2 + x2^2
    }

    vecZ7 <- function(m) replicate(m, Z())
    hist(vecZ7(m1), freq = 0, breaks = 40)
    curve(dchisq(x, df = 2), col = "blue", add = TRUE)

    vecZ8 <- function(m) replicate(m, Z())
    hist(vecZ8(m2), freq = 0, breaks = 40)
    curve(dchisq(x, df = 2), col = "blue", add = TRUE)

    vecZ9 <- function(m) replicate(m, Z())
    hist(vecZ9(m3), freq = 0, breaks = 40)
    curve(dchisq(x, df = 2), col = "blue", add = TRUE)
}

par(mfrow = c(3, 3))
task1()
task2()
task3()
