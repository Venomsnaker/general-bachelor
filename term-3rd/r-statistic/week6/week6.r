x <- c(1,2,5,7,-3,0,5,1,5,6)
y <- c(2,2,0,-5,7,8,11,9,3,2)
print(x+y)
print(x*y)
print(x-y)

z = x[x %% 2 == 0]
t = x[y %% 2 == 1]
print(z)
print(t)

a = cbind(x[x > 0], y[y>0])
print(a)

print(mean(x))
print(sd(x))
print(sd(x)/sqrt(length(x)))
print(min(x))
print(max(x))

print(mean(y))
print(sd(y))
print(sd(y)/sqrt(length(y)))
print(min(y))
print(max(y))

print(sort(x))
print(sort(y, decreasing = T))
write.table(rbind(x,y), "D:\\data.txt", sep=",")

data1 = read.csv('data01.csv')
print(data1)

fpsa = data1$FPSA
tpsa = data1$TPSA

print(mean(fpsa))
print(var(fpsa))
print(median(fpsa))

print(mean(tpsa))
print(var(tpsa))
print(median(tpsa))

par(mfrow=c(2,2))
plot(fpsa, type = 'l')
plot(tpsa, type = 'l')
boxplot(fpsa)
boxplot(tpsa)

fpsaOne = (data1[data1$K == '1',])$FPSA
fpsaZero = (data1[data1$K == '0',])$FPSA

data2 = read.csv('data02.csv')
print(data2)

out_merged <- merge(data1, data2, by = "K")

tPSA = data1$Age
data1$tPSA <- ifelse(data1$Age <= 30, 0, ifelse(data1$Age <= 50,1,2))
print(data1)

dieselTime = read.csv('diesel_time.csv')
dieselEngine = read.table('diesel_engine.dat', header = TRUE)

print(colnames(dieselTime ))
print(colnames(dieselEngine ))

summary(dieselEngine )
dieselEngine$speed[is.na(dieselEngine$speed)] <-1500
dieselEngine$load[is.na(dieselEngine$load)] <-20
summary(dieselEngine)

print(mean(dieselEngine$alcohol))
print(var(dieselEngine$alcohol))
print(sd(dieselEngine$alcohol))
print(min(dieselEngine$alcohol))
print(max(dieselEngine$alcohol))

diesel = merge(x = dieselEngine,y = dieselTime , by.x = 'run', by.y = 'X')
print(diesel )

goodRun = (diesel[diesel$delay < 1.000,])$run
print(goodRun)

print (nrow(diesel[diesel$timing == 30,]))