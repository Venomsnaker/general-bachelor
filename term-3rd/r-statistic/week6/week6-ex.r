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

    par(mfrow = c(3, 2))

    boxplot(diesel$speed, diesel$timing, diesel$delay,
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

task5()