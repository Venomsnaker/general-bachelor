task5 <- function() {
  counts <- c(63, 47, 55, 34, 29, 27, 24, 21)
  lambda <- 1 / 200
  probs <- diff(pexp(c(0, 50, 100, 150, 200, 300, 400, 500, Inf),
                     rate = lambda))
  print(chisq.test(counts, p = probs))
  print("p-value < 0.05 so the data does follow exponentail distribution.")
}

task11 <- function() {
  seat1 <- c(3, 7, 8, 4, 6, 9, 8)
  seat2 <- c(9, 8, 10, 8, 8, 5, 10)
  seat3 <- c(5, 6, 9, 3, 5, 7, 7)
  seat4 <- c(7, 8, 7, 6, 10, 6, 9)

  df <- data.frame(
    Rating = c(seat1, seat2, seat3, seat4),
    Seat = factor(rep(c("Seat 1", "Seat 2", "Seat 3", "Seat 4"), each = 7))
  )

  result <- aov(Rating ~ Seat, data = df)
  res <- summary(result)
  print(res)
  print("p-value > 0.05 so four seats aren't equally comfortable.")
}

task5()
task11()