binominal <- function(n, k, p) {
	return(choose(n,k)*p^k*(1-p)^(n-k))
}

display_binominal <- function() {
	df <- data.frame(k = c(0:8))
	Pk = binominal(8, df$k, 0.3)
	df = cbind(df, Pk)
	print(df )
}

probability_density <- function(x, mu = 0, sigma = 1) {
	return( (1/sqrt(2*pi*sigma^2)) * exp(-(x-mu)^2 / (2*sigma^2)))
}

display_probability_density() {
	intergrand <- function(x) probability_density(x, 0, 1)
	integrate(intergrand, lower = -Inf, upper = Inf)
}

binominal_cdf <- function(x) {
	return (sum(binominal(8, c(0:k), 0.3)))
}

probability_density_cdf <- function(x) {
	intergrand <- function(x) probability_density(x, 0, 1)
	return(integrate(intergrand, lower = -Inf, upper = x))
}

plot_shits <- function() {
	probability_density_cdf(1.96)$value
	binominal <- Vectorize(binominal)
	#plot(c(0:8), binominal(8, c(0:8), 0.3), type = 's')
	plot(stepfun(c(0:8), binominal(8, c(0:9), 0.3)))
}

probability_density_cdf(1.96)
#uniroot(function(x) probability_density_cdf(x) - 0.975, c(-3, 3))
