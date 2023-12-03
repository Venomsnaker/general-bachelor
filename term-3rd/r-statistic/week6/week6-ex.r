task5 <- function() {
  diesel_time <- read.csv("diesel_time.csv")
  diesel_engine <- read.table("diesel_engine.dat", header = TRUE)

  print("diesel_time Varibles: ")
  print(colnames(diesel_time))
  print("---")

  print("diesel_engine Varibles: ")
  print(colnames(diesel_engine))
  print("---")

  print(paste("diesel_engine Missing Rows: ", sum(is.na(diesel_engine))))
  diesel_engine$speed[is.na(diesel_engine$speed)] <- 1500
  diesel_engine$load[is.na(diesel_engine$load)] <- 20
  print(paste("diesel_engine Missing Rows: ", sum(is.na(diesel_engine))))
  print("---")

  print("Merged to diesel: ")
  diesel <- merge(x = diesel_engine, y = diesel_time,
                  by.x = "run", by.y = "X")
  print(diesel)
  print("---")

  print("diesel_engine Parameters: ")
  print(paste("Mean: ", mean(diesel_engine$alcohol)))
  print(paste("Var: ", var(diesel_engine$alcohol)))
  print(paste("SD: ", sd(diesel_engine$alcohol)))
  print(paste("Min: ", min(diesel_engine$alcohol)))
  print(paste("Max: ", max(diesel_engine$alcohol)))
  print("---")

  print("Delay < 1.000: ")
  print(diesel[diesel$delay < 1.000, ])$run
  print("---")

  print("Timing = 30: ")
  print(nrow(diesel[diesel$timing == 30, ]))
  print("---")

  print("Convert load to factor: ")
  diesel$load <- factor(diesel$load)
  print(diesel$load)
  print("---")

  boxplot(diesel$speed, diesel$timing, diesel$delay,
          main = "Speed, Timing and Delay",
          names = c("Speed", "Timing", "Delay"))

  plot(diesel$timing, diesel$speed, main = "Timing & Speed Scatter Plot:",
       xlab = "Timing", ylab = "Speed")

  plot(diesel$temp, diesel$press, main = "Temp & Press Scatter Plot:",
       xlab = "Temp", ylab = "Press")

  delay_intervals <- cut(diesel$delay, breaks = 4)
  frequency_table <- table(delay_intervals)
  print(frequency_table)
  barplot(frequency_table, main = "Bar Plot of Equal Delay Intervals",
          xlab = "Delay Intervals", ylab = "Frequency")
  print("---")


  delay_intervals_specific <- cut(diesel$delay,
                                  breaks = c(0.283, 0.7, 0.95, 1.2, 1.56))
  frequency_table_specific <- table(delay_intervals_specific)
  print(frequency_table_specific)
  barplot(frequency_table_specific,
          main = "Bar Plot of Specific Delay Intervals",
          xlab = "Delay Intervals", ylab = "Frequency")
}

task6 <- function() {
  data <- data.frame(year = c(1970:1979),
                     snow.cover = c(6.5, 12.0, 14.9, 10.0,
                                    10.7, 7.9, 21.9, 12.5, 14.5, 9.2))
  plot(data$year, data$snow.cover, ylab = "snow.cover",
       type = "l", xlab = "Year", main = "snow.cover Over Year")
  hist(data$snow.cover, xlab = "snow.cover",
       breaks = 8, main = "Histogram of snow.cover")

  data$logsnow.cover <- log(data$snow.cover)
  plot(data$year, data$logsnow.cover, ylab = "logsnow.cover",
       type = "l", xlab = "Year", main = "logsnow.cover Over Year")
  hist(data$logsnow.cover, xlab = "logsnow.cover",
       breaks = 8, main = "Histogram of logsnow.cover")
}

task7 <- function() {
  data <- data.frame(Temperature = c(53, 57, 63, 70, 70, 75),
                     Erosion_incidents = c(3, 1, 1, 1, 1, 0),
                     Blowby_incidents = c(2, 0, 0, 0, 0, 2),
                     Total_incidents = c(5, 1, 1, 1, 1, 1))

  plot(data$Temperature, data$Total_incidents, type = "o",
       main = "Total Incidents and Temperature",
       xlab = "Temperature (F)", ylab = "Total Incidents")
}

task8 <- function() {
  inflation1 <- data.frame(
    Year = c(1960:1980),
    US = c(1.5, 1.1,  1.1, 1.2, 1.4, 1.6, 2.8, 2.8, 4.2, 5,
           5.9, 4.3, 3.6, 6.2, 10.9, 9.2, 5.8, 6.4, 7.6, 11.4, 13.6),
    UK = c(1, 3.4, 4.5, 2.5, 3.9, 4.6, 3.7, 2.4, 4.8,
           5.2, 6.5, 9.5, 6.8, 8.4, 16, 24.2, 16.5, 15.9, 8.3, 13.4, 18)
  )

  inflation2 <- read.table(header = TRUE, text = "
    Year Japan Germany
    1960 3.6   1.5
    1961 5.4   2.3
    1962 6.7   4.5
    1963 7.7   3
    1964 3.9   2.3
    1965 6.5   3.4
    1966 6     3.5
    1967 4     1.5
    1968 5.5   18
    1969 5.1   2.6
    1970 7.6   3.7
    1971 6.3   5.3
    1972 4.9   5.4
    1973 12    7
    1974 24.6  7
    1975 11.7  5.9
    1976 9.3   4.5
    1977 8.1   3.7
    1978 3.8   2.7
    1979 3.6   4.1
    1980 8     5.5")

  inflation <- merge(inflation1, inflation2, by = "Year")
  print(inflation)
  print("---")

  print("Years when inflation < 5")
  print(sum(inflation$US > 5 | inflation$UK > 5 |
              inflation$Japan > 5 | inflation$Germany > 5))

  plot(inflation$Year, inflation$US, type = "o", col = "red",
       xlab = "Year", ylab = "US", main = "US Inflation")
  plot(inflation$Year, inflation$UK, type = "o", col = "royalblue",
       xlab = "Year", ylab = "UK", main = "UK Inflation")
  plot(inflation$Year, inflation$Japan, type = "o", col = "darkcyan",
       xlab = "Year", ylab = "Japan", main = "Japan Inflation")
  plot(inflation$Year, inflation$Germany, type = "o", col = "magenta",
       xlab = "Year", ylab = "Germany", main = "Germany Inflation")
  print("Both US and UK start low then rise drastically:")
  print("while Japan and Germany have a peak at 1970~.")

  summarise_stats <- data.frame(
    Mean = c(mean(inflation$US, na.rm = TRUE),
              mean(inflation$UK, na.rm = TRUE),
              mean(inflation$Japan, na.rm = TRUE),
              mean(inflation$Germany, na.rm = TRUE)),
    Median = c(median(inflation$US, na.rm = TRUE),
                median(inflation$UK, na.rm = TRUE),
                median(inflation$Japan, na.rm = TRUE),
                median(inflation$Germany, na.rm = TRUE)),
    Max = c(max(inflation$US, na.rm = TRUE),
            max(inflation$UK, na.rm = TRUE),
            max(inflation$Japan, na.rm = TRUE),
            max(inflation$Germany, na.rm = TRUE)),
    Min = c(min(inflation$US, na.rm = TRUE),
            min(inflation$UK, na.rm = TRUE),
            min(inflation$Japan, na.rm = TRUE),
            min(inflation$Germany, na.rm = TRUE)),
    SD = c(sd(inflation$US, na.rm = TRUE),
            sd(inflation$UK, na.rm = TRUE),
            sd(inflation$Japan, na.rm = TRUE),
            sd(inflation$Germany, na.rm = TRUE)),
    SE = c(mean(inflation$US, na.rm = TRUE) /
      sqrt(length(inflation$US) - sum(is.na(inflation$US))),
    mean(inflation$UK, na.rm = TRUE) /
      sqrt(length(inflation$UK) - sum(is.na(inflation$UK))),
    mean(inflation$Japan, na.rm = TRUE) /
      sqrt(length(inflation$Japan) - sum(is.na(inflation$Japan))),
    mean(inflation$Germany, na.rm = TRUE) /
      sqrt(length(inflation$Germany) - sum(is.na(inflation$Germany)))))
  row.names(summarise_stats) <- c("US", "UK", "Japan", "Germany")
  print(summarise_stats)
  print("We use standard deviation - sd")
  print("to judge with varible flunctuate the most: UK")
  print("---")

  inflation_dropped <- inflation[-c(21), ]
  print(inflation_dropped)
  print("---")

  linear_regression <- function(x, y) {
    n <- length(x)
    beta2 <- (sum(x * y) - n * mean(x) * mean(y)) /
      (sum(x^2) - n * mean(x)^2)
    beta1 <- mean(y) - beta2 * mean(x)
    return(c(beta1, beta2))
  }

  parameters <- linear_regression(inflation_dropped$Year, inflation_dropped$US)
  plot(inflation_dropped$Year, inflation_dropped$US,
       type = "o", col = "royalblue", xlab = "Year", ylab = "US Inflation")
  lines(inflation_dropped$Year,
        parameters[1] + inflation_dropped$Year * parameters[2],
        col = "red", type = "b")

  print("Let's Predict 1980: ")
  print(parameters[1] + 1980 * parameters[2])
  print("Actual Case")
  print(inflation$US[inflation$Year == 1980])
}

par(mfrow = c(5, 3))
task5()
task6()
task7()
task8()