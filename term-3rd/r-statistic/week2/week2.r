library(readxl)
# 22120128 - Bui Quoc Huy

# Bai 1
    sum_to_x <- function(nums, x) {
        sum <- 0

        if (x > length(nums)) return(-1)

        for (i in 1:x) sum <- sum + nums[i]
        return(sum)
    }

    display_task1 <- function(x) {
        nums <- c(1:20)
        print("CAU 1")
        print("Cho day du lieu tu 1 den 20:")
        print(paste("Tong cua:", x, "so dau tien la: "))
        print(sum_to_x(nums, x))
        print("---")
    }

# Bai 2
    get_volume <- function(r) {
        return(4 * pi * (r^3) / 3)
    }

    display_volumes <- function(start, end) {
        r <- c(start:end)
        v <- c(get_volume(r))
        df <- data.frame(r, v)
        print(df)
    }
    
    display_task2 <- function() {
        print("Cau 2 ---")
        display_volumes(3, 20)
        print("---")
    }

# Bai 3
    modify_index <- function(cols) {
        #cols[1] == age
        if (cols[1] <= 60) return(0)
        if (60 < cols[1] && cols[1] <= 70) return(1)
        if (70 < cols[1] && cols[1] <= 80) return(2)
        if (cols[1] > 80) return(3)
    }

    display_task3 <- function(filePath) {
        print("CAU 3 ---")
        df <- read_excel(filePath)
        Index = apply(df, MARGIN = 1, modify_index)
        df <- cbind(df, Index)
        print(df)
        print("---")
    }
    

# Bai 4
    get_max_height_range <- function(df) {
        # Return the highest height range with n > 0
        df <- subset(df, n > 0)
        n = dim(df)[1]
        return(c(df[n,]$a, df[n,]$b))
    }

    get_min_height_range <- function(df) {
        # Return the lowest height range with n > 0
        df <- subset(df, n > 0)
        return(c(df[1,]$a, df[1,]$b))
    }

    get_mean_height <- function(df) {
        # Assume each row average_height = (a + b) / 2
        # Return the mean height across the dataset
        average_heights <- rep((df$a + df$b)/2, df$n)
        return(mean(average_heights))
    }

    get_variance <- function(df) {
        # Return the variance
        average_heights <- rep((df$a + df$b)/2, df$n)
        mu <- get_mean_height(df)
        variance <- sum((average_heights - mu)^2) / sum(df$n)
        return(variance)
    }

    display_task4 <- function(filePath) {
        print("CAU 4 ---")
        df <- read_excel(filePath)
        print(df)
        print("Khoang do cao be nhat: ")
        print(get_min_height_range(df))
        print("Khoang do cao lon nhat: ")
        print(get_max_height_range(df))
        print(paste("Trung binh mau (lay trung binh cong do cao tung khoang): ", get_mean_height(df)))
        print(paste("Phuong sai mau hieu chinh: ", get_variance(df)))
        print("---")
    }

# Bai 5
    get_p_quantiles <- function(nums, p) {
        p_quantiles <- -1
        n <- length(nums)
        i <- (p / 100 * n)
        print(i)

        if (i %% 1 == 0) {
            p_quantiles <- (nums[i] + nums[i+1]) / 2
        }
        else {
            i <- round(i, digits = 0)
            p_quantiles <- nums[i]
        }
        return(p_quantiles)
    }

    display_task5 <- function(p) {
        print("Cau 5 ---")
        print("Khoi tao mang 50 -> 1, sau do xap xep tang dan (nhap vao mang random trong thuc te): ")
        nums_fifty <- c(50:1)
        print(nums_fifty)
        print("---")

        nums_fifty = sort(nums_fifty, decreasing = FALSE)
        print("Tren mot mang tu 1 den 50: ")
        print(nums_fifty)

        print(paste("P = ", p))
        p_quantiles = get_p_quantiles(nums_fifty, p)
        print(paste("Phan vi thu ", p, " la ", p_quantiles))
    }
    
display_task1(5)
display_task2()
display_task3("week2/data01.xlsx")
display_task4("week2/data11.xlsx")
display_task5(40)