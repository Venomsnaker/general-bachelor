task7 <- function() {
  temperature <- read.csv("temperature.csv")
  temp <- temperature$temp
  usage <- temperature$usage.1000
  n <- length(temp)

  # a
  plot(temp, usage)
  model <- lm(usage ~ temp)
  abline(model)
  print("Estimated residual variance: ")
  sse <- sum((usage - fitted(model))^2)
  mse <- sse / (n - 2)
  print(mse)
  print("-----")

  # b
  print("Temp = 55F: ")
  res <- predict(model, newdata = data.frame(temp = 55))
  print(res)
  print("-----")

  # c
  print("beta1: ")
  print(getElement(coef(model), "temp"))
  print("-----")

  # d
  print("Temp = 47F: ")
  predicted_usage <- predict(model, newdata = data.frame(temp = 47))
  residuals_usage <- usage - predicted_usage
  print(predicted_usage)
  print(residuals_usage)
  print("-----")

  # e
  print("Test beta1 = 10")
  beta1 <- getElement(coef(model), "temp")
  temp_mean <- mean(temp)
  sxx <- sum((temp - temp_mean)^2)
  t <- (beta1 - 10) / sqrt(mse / sxx)
  t_test <- qt(1 - 0.01 / 2, df = n - 2)

  if (abs(t) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  print("P-value: ")
  print(2 * pt(t, df = n - 2, lower.tail = FALSE))
  print("-----")

  # f
  print("Test beta0 = 0")
  beta0 <- getElement(coef(model), "(Intercept)")
  t <- (beta0) / sqrt(mse * (1 / n + temp_mean^2 / sxx))
  t_test <- qt(1 - 0.01 / 2, df = n - 2)

  if (abs(t) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  print("P-value: ")
  print(2 * pt(t, df = n - 2, lower.tail = FALSE))
  print("-----")

  # g
  print("Estimate 99%")
  estimate_range_beta1 <- qt(1 - 0.01 / 2, df = n - 2) * sqrt(mse / sxx)
  estimate_range_beta0 <- qt(1 - 0.01 / 2, df = n - 2) *
    sqrt(mse * (1 / n + temp_mean^2 / sxx))
  print("beta0 range:")
  print(c(beta0 - estimate_range_beta0, beta0 + estimate_range_beta0))
  print("beta1 range:")
  print(c(beta1 - estimate_range_beta1, beta1 + estimate_range_beta1))
  print("-----")

  # h, i
  print("Estimate 95% - 55F")
  temp_mean <- 55
  sxx <- sum((temp - temp_mean)^2)
  estimate_range_beta1 <- qt(1 - 0.01 / 2, df = n - 2) * sqrt(mse / sxx)
  estimate_range_beta0 <- qt(1 - 0.01 / 2, df = n - 2) *
    sqrt(mse * (1 / n + temp_mean^2 / sxx))
  lower <- (beta0 - estimate_range_beta0) +
    (beta1 - estimate_range_beta1) * 55
  upper <- (beta0 + estimate_range_beta0) +
    (beta1 + estimate_range_beta1) * 55
  print("y range (around 55) base on beta1-0:")
  print(c(lower, upper))

  estimate_range_y <- qt(1 - 0.05 / 2, df = n - 2) *
    sqrt(mse * (1 + 1 / n))
  print("y range (around 55):")
  print(c(res - estimate_range_y, res + estimate_range_y))
  print("-----")

  # j
  plot(model$fitted.values, resid(model),
    xlab = "Fitted values",
    ylab = "Residuals", main = "Residuals vs Fitted"
  )
  abline(h = 0, lty = 4)
  predicted_values <- predict(model, newdata = data.frame(temp))
  qqnorm(predicted_values)
  qqline(predicted_values)
  print("-----")
}

task8 <- function() {
  house_prices <- read.csv("house.price.csv")
  prices <- house_prices$sale.price
  taxes <- house_prices$taxes
  n <- length(prices)
  print(prices)
  print(taxes)

  # a
  plot(taxes, prices)
  model2 <- lm(prices ~ taxes)
  abline(model2)
  print("Estimated residual variance: ")
  sse <- sum((prices - fitted(model2))^2)
  mse <- sse / (n - 2)
  print(mse)
  print("-----")

  # b
  print("Tax = 7.5: ")
  res <- predict(model2, data.frame(taxes = 7.5))
  print(res)
  print("-----")

  # c
  print("Tax = 5.898: ")
  predicted_price <- predict(model2, newdata = data.frame(taxes = 5.898))
  residuals_price <- prices - predicted_price
  print(predicted_price)
  print(residuals_price)
  print("-----")

  # d
  predicted_values <- predict(model2, newdata = data.frame(taxes))
  plot(prices, predicted_values)
  print("Insufficient when using linear regression.")
  print("-----")

  # e
  print("Test beta1 = 0")
  beta1 <- getElement(coef(model2), "taxes")
  taxes_mean <- mean(taxes)
  sxx <- sum((taxes - taxes_mean)^2)
  t <- (beta1) / sqrt(mse / sxx)
  t_test <- qt(1 - 0.05 / 2, df = n - 2)

  if (abs(t) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  print("P-value: ")
  print(2 * pt(t, df = n - 2, lower.tail = FALSE))
  print("-----")

  # f
  print("Test beta0 = 0")
  beta0 <- getElement(coef(model2), "(Intercept)")
  t <- (beta0) / sqrt(mse * (1 / n + taxes_mean^2 / sxx))
  t_test <- qt(1 - 0.05 / 2, df = n - 2)

  if (abs(t) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  print("P-value: ")
  print(2 * pt(t, df = n - 2, lower.tail = FALSE))
  print("-----")

  # g
  print("Estimate 95%")
  estimate_range_beta1 <- qt(1 - 0.05 / 2, df = n - 2) * sqrt(mse / sxx)
  estimate_range_beta0 <- qt(1 - 0.05 / 2, df = n - 2) *
    sqrt(mse * (1 / n + taxes_mean^2 / sxx))
  print("beta0 range:")
  print(c(beta0 - estimate_range_beta0, beta0 + estimate_range_beta0))
  print("beta1 range:")
  print(c(beta1 - estimate_range_beta1, beta1 + estimate_range_beta1))
  print("-----")

  # h
  print("Estimate 95% - Tax = 7.5")
  estimate_range_y <- qt(1 - 0.05 / 2, df = n - 2) *
    sqrt(mse * (1 + 1 / n + (taxes_mean - 7.5)^2 / sxx))
  print("y range (around 55):")
  print(c(res - estimate_range_y, res + estimate_range_y))
  print("-----")

  # i
  print("Correlation checking:")
  ssr <- sum((fitted(model2) - taxes_mean)^2)
  sst <- ssr + sse
  r <- sqrt(ssr / sst)
  t <- r * sqrt((n - 2) / (1 - r^2))
  t_test <- qt(1 - 0.05 / 2, df = n - 2)

  if (abs(t) > t_test) {
    print("Reject")
  } else {
    print("Can't reject")
  }
  print("P-value: ")
  print(2 * pt(t, df = n - 2, lower.tail = FALSE))
  print("-----")


  # j
  plot(model2$fitted.values, resid(model2),
    xlab = "Fitted values",
    ylab = "Residuals", main = "Residuals vs Fitted"
  )
  abline(h = 0, lty = 4)
  predicted_values <- predict(model2, newdata = data.frame(taxes))
  qqnorm(predicted_values)
  qqline(predicted_values)
  print("-----")
}


par(mfrow = c(3, 3))
task7()
task8()
