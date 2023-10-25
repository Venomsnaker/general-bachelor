library("xlsx")

sum_to_x <- function(nums, x) {
    sum <- 0
    if (x > length(nums)) return(-1)

    for (i in 1:x) {
        sum <- sum + nums[i]
    }
    return(sum)
}

nums <- c(1, 2, 3, 4, 5, 6, 7, 8)
print(sum_to_x(nums, 4))

get_volume <- function(r) {
    return(4 * pi * (r^3) / 3)
}

display_volumes <- function(start, end) {
    r <- c(start:end)
    v <- c(get_volume(r))
    df <- data.frame(r, v)
    print(df)
}

display_volumes(3, 20)

my_data <- read.xlsx("data01", 1)
print(my_data)