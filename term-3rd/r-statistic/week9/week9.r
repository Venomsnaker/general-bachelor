task2 <- function() {
  print("Cau 2")
  diameter <- read.csv("diameter.csv")
  steel1 <- diameter$extru.ma.1
  steel2 <- diameter$extru.ma.2
  steel2 <- na.omit(steel2)
  mean1 <- mean(steel1)
  mean2 <- mean(steel2)
  alpha <- 0.05
  s1 <- sd(steel1)
  s2 <- sd(steel2)
  n1 <- length(steel1)
  n2 <- length(steel2)

  t0 <- (mean1 - mean2) / sqrt(s1^2 / n1 + s2^2 / n2)
  t_test <- qt(1 - alpha / 2, df = n1 + n2 - 2)

  print("Check theory x1 != x2: ")
  if (abs(t0) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  p_value <- 2 * (pt(abs(t0), df = n1 + n2 - 2, lower.tail = FALSE))

  print("P-Value: ")
  print(p_value)
  df <- n1 + n2 - 2
  error <- qt(1 - alpha / 2, df) * sqrt((s1^2 / n1) + (s2^2 / n2))
  confidence_interval <- c((mean1 - mean2) - error, (mean1 - mean2) + error)
  print("Confidence Interval: ")
  print(confidence_interval)

  test_leg_oneside <- function(x, y, mu0, alpha) {
    mean_x <- mean(x)
    mean_y <- mean(y)
    s_x <- sd(x)
    s_y <- sd(y)
    n_x <- length(x)
    n_y <- length(y)
    t0 <- (mean_x - mean_y - mu0) / sqrt(s_x^2 / n_x + s_y^2 / n_y)
    t_test <- qt(1 - alpha, df = n_x + n_y - 2)

    print("Check theory x1 > x2: ")
    if (t0 > t_test) {
      print("Reject")
    } else {
      print("Can't reject")
    }
    p_value <- pt(t0, df = n_x + n_y - 2, lower.tail = FALSE)

    print("P-Value: ")
    print(p_value)
  }

  test_geg_oneside <- function(x, y, mu0, alpha) {
    mean_x <- mean(x)
    mean_y <- mean(y)
    s_x <- sd(x)
    s_y <- sd(y)
    n_x <- length(x)
    n_y <- length(y)
    t0 <- (mean_x - mean_y - mu0) / sqrt(s_x^2 / n_x + s_y^2 / n_y)
    t_test <- -qt(1 - alpha, df = n_x + n_y - 2)

    print("Check theory x1 < x2: ")
    if (t0 < t_test) {
      print("Reject")
    } else {
      print("Can't reject")
    }
    p_value <- pt(t0, df = n_x + n_y - 2)

    print("P-Value: ")
    print(p_value)
  }

  print("---")
  test_leg_oneside(steel1, steel2, 0, 0.05)
  print("---")
  test_geg_oneside(steel1, steel2, 0, 0.05)
  print("---")
}

task6 <- function() {
  print("Cau 6")
  time <- read.csv("prop.time.csv")
  time <- time[-1, ]
  des1 <- time$Time
  des1 <- strtoi(des1, base = 10)
  des2 <- time$X.1
  des2 <- strtoi(des2, base = 10)
  print(des1)
  print(des2)

  test_bothsize_pair <- function(x, y, mu0, alpha) {
    n <- length(x)
    d <- x - y - mu0

    t0 <- mean(d) / (sd(d) / sqrt(n))
    t_test <- qt(1 - alpha / 2, df = n - 1)

    print("Check theory x1 != x2: ")
    if (abs(t0) > t_test) {
      print("Reject")
    } else {
      print("Can't reject")
    }
    p_value <- pt(t0, df = n - 1, lower.tail = FALSE)

    print("P-Value: ")
    print(p_value)
  }

  test_leg_oneside_pair <- function(x, y, mu0, alpha) {
    n <- length(x)
    d <- x - y - mu0

    t0 <- mean(d) / (sd(d) / sqrt(n))
    t_test <- qt(1 - alpha, df = n - 1)

    print("Check theory x1 > x2: ")
    if (t0 > t_test) {
      print("Reject")
    } else {
      print("Can't reject")
    }
    p_value <- pt(t0, df = n - 1, lower.tail = FALSE)

    print("P-Value: ")
    print(p_value)
  }

  test_geg_oneside_pair <- function(x, y, mu0, alpha) {
    n <- length(x)
    d <- x - y - mu0

    t0 <- mean(d) / (sd(d) / sqrt(n))
    t_test <- -qt(1 - alpha, df = n - 1)

    print("Check theory x1 < x2: ")
    if (t0 < t_test) {
      print("Reject")
    } else {
      print("Can't reject")
    }
    p_value <- pt(t0, df = n - 1)

    print("P-Value: ")
    print(p_value)
  }
  test_bothsize_pair(des1, des2, 0, 0.05)
  print("---")
  test_leg_oneside_pair(des1, des2, 0, 0.05)
  print("---")
  test_geg_oneside_pair(des1, des2, 0, 0.05)
  print("---")
}

prop_test_leq <- function(x, y, n_x, n_y, alpha) {
  p_x <- length(x) / n_x
  p_y <- length(y) / n_y
  p_hat <- (n_x * p_x + n_y * p_y) / (n_x + n_y)
  se <- sqrt((p_x * (1 - p_x) / n_x) + (p_y * (1 - p_y) / n_y))

  z0 <- (p_x - p_y) / sqrt(p_hat * (1 - p_hat) * (1 / n_x + 1 / n_y))
  z_test <- (1 - alpha)

  print("Check theory x > y: ")
  if (z0 > z_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  p_value <- pnorm(z0)
  print("P-Value: ")
  print(p_value)
  ci <- z_test * se
  lower_bound <- (mean(x) - mean(y)) - ci
  upper_bound <- (mean(x) - mean(y)) + ci
  cat(paste("The confidence interval: [", lower_bound, ", ", upper_bound, "]"))
}

task10 <- function() {
  print("Cau 10")
  revenue <- read.csv("Profit-th05.csv")
  revenue_dist1 <- revenue$Dist.1
  revenue_dist3 <- revenue$Dist.3
  good_revenue_dist1 <- revenue_dist1[revenue_dist1 > 600]
  good_revenue_dist3 <- revenue_dist3[revenue_dist3 > 600]
  prop_test_leq(good_revenue_dist1, good_revenue_dist3,
                length(revenue_dist1), length(revenue_dist3), 0.05)
  print("---")
}

task11 <- function() {
  print("Cau 11")
  salary <- read.csv("Inf.Sal.csv")
  salary_hcm <- salary$HCM
  salary_hn <- salary$HaNoi
  salary_hn <- na.omit(salary_hn)
  high_salary_hcm <- salary_hcm[salary_hcm > 11.5]
  high_salary_hn <- salary_hn[salary_hn > 11.5]
  prop_test_leq(high_salary_hcm, high_salary_hn,
                length(salary_hcm), length(salary_hn), 0.05)
  print("---")
}

task2()
task6()
task10()
task11()
