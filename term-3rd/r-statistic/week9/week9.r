data <- read.csv("volume.csv")
res <- t.test(data$machine1, data$macine2, c("two.sided"), 0.95)
