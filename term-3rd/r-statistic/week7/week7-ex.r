task4 <- function(x, alpha) {
  print("Cau 4")
  heights_low <- c(1.2, 1.4, 1.6, 1.8, 2.0)
  heights_high <- c(1.4, 1.6, 1.8, 2.0, 2.2)
  frequencies <- c(6, 34, 31, 42, 12)
  heights <- (heights_low + heights_high) / 2
  x <- rep(heights, times = frequencies)
  x <- as.vector(x)

  ci_mean <- function(x, alpha) {
    n <- length(x)
    epsilon <- qnorm(1 - alpha / 2) * (sd(x) / sqrt(n))
    return(c(mean(x) - epsilon, mean(x) + epsilon))
  }

  ci_prop <- function(f, n, alpha) {
    p_hat <- f / n
    epsilon <- qnorm(1 - alpha / 2) * sqrt(p_hat * (1 - p_hat) / n)
    return(c(p_hat - epsilon, p_hat + epsilon))
  }

  res <- ci_mean(x, 0.05)
  print(paste("95% Confidence Interval: ", res[1], "-", res[2]))
  print("---")

  f <- length(x[x >= 1.7])
  n <- length(x)
  res <- ci_prop(f, n, 0.05)
  print(paste("95% Binomial Proportion Estimation Range (height > 1.7)",
              res[1], "-", res[2]))
  print("---")
  print(" ")
}

task5 <- function() {
  print("Cau 5")
  ktc_tb <- function(sample_mean, sigma = Inf, s, n, alpha) {
    if (sigma != Inf) {
      epsilon <- qnorm(1 - alpha / 2) * sigma / sqrt(n)
    } else {
      if (n >= 30) {
        epsilon <- qnorm(1 - alpha / 2) * (s / sqrt(n))
      } else {
        epsilon <- qt(1 - alpha / 2, df = n - 1) * (s / sqrt(n))
      }
    }
    return(c(sample_mean - epsilon, sample_mean + epsilon))
  }

  root <- c(1, 2, 3)
  ex1 <- rep(root, times = c(1, 2, 3))
  ex1 <- as.vector(ex1)
  res1 <- ktc_tb(sample_mean = mean(ex1), s = sd(ex1),
                 n = length(ex1), alpha = 0.1)
  print(paste("90% Confidence Interval: ", res1[1], "-", res1[2]))
  print("---")

  ex2 <- rep(root, times = c(30, 20, 10))
  ex2 <- as.vector(ex2)
  print("Repeat ex1 but with Frequencies = 30, 20, 10")
  res2 <- ktc_tb(sample_mean = mean(ex2), s = sd(ex2),
                 n = length(ex2), alpha = 0.1)
  print(paste("90% Confidence Interval: ", res2[1], "-", res2[2]))
  print("---")
  print(" ")
}

task6 <- function() {
  print("Cau 6")
  ktc_tb_mau <- function(x, sigma = Inf, alpha) {
    n <- length(x)
    sample_mean <- mean(x)

    if (sigma != Inf) {
      epsilon <- qnorm(1 - alpha / 2) * sigma / sqrt(n)
    } else {
      if (n >= 30) {
        s <- sd(x)

        epsilon <- qnorm(1 - alpha / 2) * (s / sqrt(n))
      } else {
        epsilon <- qt(1 - alpha / 2, df = n - 1) * (s / sqrt(n))
      }
    }
    return(c(sample_mean - epsilon, sample_mean + epsilon))
  }

  root <- c(1, 2, 3)
  ex1 <- rep(root, times = c(1, 2, 3))
  ex1 <- as.vector(ex1)
  res1 <- ktc_tb_mau(ex1, sigma = sd(ex1), alpha = 0.1)
  print(paste("90% Confidence Interval: ", res1[1], "-", res1[2]))
  print("---")

  ex2 <- rep(root, times = c(30, 20, 10))
  ex2 <- as.vector(ex2)
  print("Repeat ex1 but w/t sigma")
  res2 <- ktc_tb_mau(ex2, alpha = 0.1)
  print(paste("90% Confidence Interval: ", res2[1], "-", res2[2]))
  print("---")
}

task4()
task5()
task6()