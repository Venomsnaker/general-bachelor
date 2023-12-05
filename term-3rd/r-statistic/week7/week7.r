task1 <- function() {
  p <- 0.5
  n <- 30
  m <- 50
  alpha <- 0.05

  p_hat <- rbinom(50, 30, 0.5) / n
  epsilon <- qnorm(1 - alpha/2) * sqrt((1-p_hat) * p_hat / n)
  matplot(rbind(p_hat - epsilon, p_hat + epsilon), rbind(1:m, 1:m), type = "l")
  abline(v = p)
}

task2 <- function() {
  data <- read.csv("data31.csv")
  print(data)

  x <- data$profit

  ci_mean <- function(x, alpha) {
    n <- length(x)

    epsilon <- qnorm(1 - alpha / 2) * (sd(x) / sqrt(n))
    return(c(mean(x) - epsilon, mean(x) + epsilon))
  }

  res <- ci_mean(x, 1 - 0.95)
  print(res)
}

task3 <- function() {
  data <- read.csv("data32.csv")
  read.csv("data32.csv")
  x <- data$KHTN

  ci_prop <- function(f, n, alpha) {
    p_hat <- f / n
    epsilon <- qnorm(1 - alpha / 2) * sqrt(p_hat * (1 - p_hat) / n)
    return(c(p_hat - epsilon, p_hat + epsilon))
  }

  f <- sum(data$KHTN > 5)
  n <- length(data$KHTN)

  alpha_list <- c(0.1, 0.05, 0.01)
  for (alpha in alpha_list) {
    print(ci_prop(f, n, alpha))
  }
}

task3()