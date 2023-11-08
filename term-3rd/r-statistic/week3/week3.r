binominal <- function(n, k, p) {
	return(choose(n,k)*p^k*(1-p)^(n-k))
}

binominal_cdf <- function(n, p, k) {
	return (sum(binominal(n, c(0:k), p)))
}

probability_density <- function(x, mu = 0, sigma = 1) {
	return( (1/sqrt(2*pi*sigma^2)) * exp(-(x-mu)^2 / (2*sigma^2)))
}

probability_density_cdf <- function(x, mu = 0, sigma = 1) {
	intergrand <- function(x) probability_density(x, mu, sigma)
	return(integrate(intergrand, lower = -Inf, upper = x)$value)
}

plot_func <- function() {
	plot(stepfun(c(0:8), binominal(8, c(0:9), 0.3)))
}

plot_func()