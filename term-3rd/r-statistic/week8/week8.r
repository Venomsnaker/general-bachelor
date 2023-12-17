scores_band <- c(5:10)
frequencies <- c(5, 10, 15, 20, 12, 8)
scores <- rep(scores_band, time = frequencies)
stem(scores)

test_geq_oneside <- function(x, phi0, alpha) {
  n <- length(x)
  z <- (mean(x, na.rm = FALSE) - phi0) * sqrt(n) / sd(x)

  if (z > qnorm(1 - alpha)) {
    print("Reject the theory.")
  } else {
    print("Doesn't have enough evidence to rejected the theory.")
  }
  p <- pnorm(abs(z))
  return(p)
}

test_leq_oneside <- function(x, phi0, alpha) {
  n <- length(x)
  z <- (mean(x, na.rm = FALSE) - phi0) * sqrt(n) / sd(x)

  if (z < qnorm(1 - alpha)) {
    print("Reject the theory.")
  } else {
    print("Doesn't have enough evidence to rejected the theory.")
  }
  p <- 1 - pnorm(abs(z))
  return(p)
}

data <- read.csv("profit.csv")
profit <- data$profit
hist(profit)
good_profit <- profit[profit > 60]
n <- length(good_profit)
epsilon <- qt(1 - 0.01, n - 1) * sd(good_profit) / sqrt(n)
paste(mean(good_profit) - epsilon, mean(good_profit) + epsilon)