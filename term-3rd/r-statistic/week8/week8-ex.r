load(file = "data04.rda")

task3 <- function() {
  print("Cau 3")
  data <- read.table(file = "teen-birth-rate-2002.txt",
                     header = TRUE, sep = "\t")
  birth <- data[, -1]

  x_ <- apply(birth, 2, mean, na.rm = TRUE)
  s <- apply(birth, 2, sd, na.rm = TRUE)
  n <- colSums(!is.na(birth))
  mu <- sum(x_ * n) / sum(n)
  z <- (x_ - mu) * sqrt(n) / s
  p <- pnorm(2 * (1 - abs(z)))
  p <- round(p, digits = 1)
  df <- data.frame(x_, s, n, mu, z, p)
  print(df)
  print("---")
}

task4 <- function() {
  print("Cau 4")
  print("Pick H1: p > 0.6")
  survey_agree <- survey[survey == 1]
  n <- 80
  alpha <- 0.05
  p <- length(survey_agree) / n
  p0 <- 0.6

  z <- (p - p0) * sqrt(n) / sqrt(p0 * (1 - p0))
  z_test <- qnorm(1 - alpha)
  if (z > z_test) {
    print("Reject the theory that p > 0.6 - No change is made")
  } else {
    print("Doesn't have enough evidence to rejected the theory that p > 0.6 
          - Changes are made.")
  }
  print("---")
}

task5 <- function() {
  print("Cau 5")
  p <- 0.2
  p0 <- 0.15
  n <- 100
  alpha <- 0.05

  z <- (p - p0) * sqrt(n) / sqrt(p0 * (1 - p0))
  z_test <- qnorm(1 - alpha / 2)

  if (abs(z) > z_test) {
    print("Reject the theory that p = 0.15.")
  } else {
    print("Doesn't have enough evidence to rejected the theory that p = 0.15.")
  }
  print("---")
}

task6 <- function() {
  print("Cau 6")
  data <- read.csv("times.csv")
  data_khtn <- data$KHTN
  data_khtn_larger_than_5 <- data_khtn[data_khtn > 5]
  alpha <- 0.05

  p_ <- length(data_khtn_larger_than_5) / length(data_khtn)
  z <- (p_ - 0.5) * sqrt(length(data_khtn)) / sqrt(0.5 * (1 - 0.5))
  z_test <- qnorm(1 - alpha / 2)

  if (abs(z) > z_test) {
    print("Reject the theory that p = 0.5.")
  } else {
    print("Doesn't have enough evidence to rejected the theory that p = 0.5.")
  }
  print("---")

  proptest_geq <- function(f, n, p0, alpha) {
    p_ <- f / n
    z <- (p_ - p0) * sqrt(n) / sqrt(p0 * (1 - p0))
    z_test <- qnorm(1 - alpha)

    if (z > z_test) {
      print("Reject the theory.")
    } else {
      print("Doesn't have enough evidence to rejected the theory.")
    }
    p <- 1 - pnorm(z)
    return(p)
  }

  proptest_leq <- function(f, n, p0, alpha) {
    p_ <- f / n
    z <- (p_ - p0) * sqrt(n) / sqrt(p0 * (1 - p0))
    z_test <- -qnorm(1 - alpha)

    if (z < z_test) {
      print("Reject the theory.")
    } else {
      print("Doesn't have enough evidence to rejected the theory.")
    }
    p <- pnorm(z)
    return(p)
  }
  print("p-value of proptest_geq:")
  print(proptest_geq(length(data_khtn_larger_than_5),
                     length(data_khtn), 0.5, 0.05))
  print("p-value of proptest_leq:")
  print(proptest_leq(length(data_khtn_larger_than_5),
                     length(data_khtn), 0.5, 0.05))
  print("---")
}

test_mean <- function(x, mu, s, alpha = 0.05,
                      ha = c("neq", "greater", "smaller")) {
  x_hat <- mean(x)
  n <- length(x)
  t0 <- (x_hat - mu) * sqrt(n) / s
  ha <- match.arg(ha)

  if (ha == "neq") {
    critical_t <- qt(df = n - 1, 1 - alpha / 2)
    ho <- ifelse(abs(t0) > critical_t, "Reject", "Do not reject")
    p <- 2 * pt(t0, n - 1, lower.tail = FALSE)
  }
  if (ha == "smaller") {
    critical_t <- qt(df = n - 1, 1 - alpha)
    ho <- ifelse(t0 < -critical_t, "Reject", "Do not reject")
    p <- pt(t0, n - 1, lower.tail = FALSE)
  }
  if (ha == "greater") {
    critical_t <- qt(df = n - 1, 1 - alpha)
    ho <- ifelse(t0 > critical_t, "Reject", "Do not reject")
    p <- pt(t0, n - 1)
  }
  results <- list(t0, critical_t, alpha, ho, p)
  names(results) <- c("z", "critical_t", "alpha", "ho", "p")
  class(results) <- "table"
  print(results)
  print("---")
}

task7 <- function() {
  print("Cau 7")
  scores_band <- c(5:10)
  frequencies <- c(5, 10, 15, 20, 12, 8)
  scores <- rep(scores_band, time = frequencies)
  test_mean(scores, 7.5, 1.41, alpha = 0.05)
}

task8 <- function() {
  nd <- rnorm(100)
  bd <- rbinom(100, 50, 0.5)

  print("Cau 8")
  test_mean(nd, 1.96, sd(nd), ha = "neq")
  test_mean(nd, 1.96, sd(nd), ha = "greater")
  test_mean(nd, 1.96, sd(nd), ha = "smaller")
  test_mean(nd, 1.7, sd(nd), ha = "neq")
  test_mean(nd, 1.7, sd(nd), ha = "greater")
  test_mean(nd, 1.7, sd(nd), ha = "smaller")
  test_mean(bd, 18, sd(bd), ha = "neq")
  test_mean(bd, 18, sd(bd), ha = "greater")
  test_mean(bd, 18, sd(bd), ha = "smaller")
}

task3()
task4()
task5()
task6()
task7()
task8()