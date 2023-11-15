task1 <- function() {
    n <- 100
    x <- rnorm(n, 0, 1)
    y <- x^2
    hist(y, freq = 0, breaks = 40)
    curve(dchisq(x, df = 1), from = 0, to = 12, col = "blue", add = T)
}

task2 <- function() {
    x <- rchisq(100, 3)
    y <- rchisq(100, 5)

    hist(x + y, freq = 0, breaks = 40)
    curve(dchisq(x, df = 8), from = 0, to = 20, col = "blue", add = T)
}

task3 <- function() {
    n <- 5
    x <- rnorm(1000, 0, 1)
    y <- rchisq(1000, 5)
    z <- x / (sqrt(y / n))
    hist(z, freq = 0, breaks = 40)
    curve(dt(x, df = n), from = -12, to = 12, col = "blue", add = T)
}

task4 <- function() {
    n <- 10
    m <- 1000
    mu <- 2
    sigma <- 2

    meanX <- function() {
        x <- rnorm(n, mu, sigma)
        x_tb <- mean(x)
    }

    sample.meanX <- function(m) {
        replicate(m, meanX())
    }
    hist(sample.meanX(m), freq = 0, breaks = 40)
    curve(dnorm(x, mu, sigma / sqrt(n)), col = "red", add = T)
}

task5 <- function() {
    n <- 10
    m <- 1000
    mu <- 2
    sigma <- 2

    meanX <- function() {
        x <- rnorm(n, mu, sigma)
        x <- ((n - 1) * (var(x))) / sigma^2
    }

    sample.meanX <- function(m) {
        replicate(m, meanX())
    }
    hist(sample.meanX(m), freq = 0, breaks = 40)
    curve(dchisq(x, n - 1), col = "red", add = T)
}
