import sys
import math

def factor(n):
    res = 1

    for i in range(1, n+1):
        res *= i
    return res

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def convertDecToBin(n):
    if n >= 1:
        convertDecToBin(n // 2)
    print(n % 2, end=' ')


def getFibo(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return getFibo(n-1) + getFibo(n-2)


def getBrainF_Pattern(n):
    if n % 2 == 0:
        return n/2
    else:
        return 3 * n + 1

def getFactorialSum():
    n = int(input("Input n = "))    
    res = 0

    for i in range(1, n+1):
        res += factor(i)
    print(res)
    
def getDivisors():
    n = int(input("Input n = "))
    res, count = 0, 0

    print("Divisors list: ")
    for i in range(1, n+1):
        if n % i == 0:
            print(i, " ", end="")
            count += 1
            res += i
    print()
    print("Count = ", count)
    print("Res = ", res)

def findClosestPrimeNumber():
    n = 0

    while n >= 50 or n <= 0:
        n = int(input("Input 0 < n < 50 = "))

    flag = isPrime(n)

    if flag == True:
        print(n, " is a prime number.")
    else:
        print(n, " is not a prime number.")
    for i in range(n-1, 1, -1):
        if isPrime(i):
            print("Largest prime number < ", n, " is: ", i)
            break
    
def getEulersFormula():
    a = int(input("Input a = "))
    b = int(input("Input b = "))
    gcd = gcd(a, b)
    print("gcd = ", gcd)

    # Find x, y satisfy a*x + b*y = res
    x, y = 0, 0

    while True:
        x += 1
        y = (gcd - a*x)/b

        if y.is_integer():
            break
        # Change sign
        x = -x
        y = (gcd - a * x) / b

        if y.is_integer():
            break
    print("x = ", x)
    print("y = ", y)
    print("lcm = ", a*b/gcd(a, b))

def printMultiplicationTable():
    n = int(input("Input n = "))

    for i in range(1, 9):
        for j in range(1, 9):
            print(i, "*", j, "=", i * j, sep="_")
        print()

def printTriangle():
    n = int(input("Input n = "))

    for i in range(n):
        count = 2 * i + 1

        for _ in range(n - i - 1):
            print(" ", end='')
        for _ in range(count):
            print("*", end='')
        print()         

def printExponentialSalary():
    n, sum = 0, 0
    while n < 1:
        n = int(input("Input n >= 1 = "))
    
    for i in range(n):
        print("The amount earn in day ", i, " is ", 2 ** i)
        sum += (2 ** i)
    print("Sum = ", sum)

def getAnimalsNumber():
    # Dogs & Chicken
    num_dogs, num_chicken = 0, 0
    num_sum = int(input("Input the total number of dogs and chicken: "))
    num_legs = int(input("Input the total number of dogs and chicken LEGS: "))

    for i in range(1, num_sum):
        num_dogs = i
        num_chicken = num_sum - num_dogs
        if num_dogs * 4 + num_chicken * 2 == num_legs:
            break

    print("Dogs: ", num_dogs)
    print("Chicken: ", num_chicken)

def getPopulationProjection():
    population_a = int(input("Input population_a = "))
    population_b = int(input("Input population_b = "))
    growth_rate_a = float(input("Input growth_rate_a = "))
    growth_rate_b = float(input("Input growth_rate_b = "))
    res = 0

    while(True):
        res += 1
        population_a = population_a + population_a * growth_rate_a
        population_b = population_b + population_b * growth_rate_b
        if (population_a > population_b):
            break
    print(res)

def performCalculation():
    num_first = int(input("Input the first number: "))
    num_second = int(input("Input the second number: "))
    print("Basic Calculator")
    print("0. Stop")
    print("1. Plus")
    print("2. Minus")
    print("3. Multiply")
    print("4. Divide")

    choice = int(input("Your choice = "))
    if choice == 0:
        sys.exit()

    if choice == 1:
        print(num_first, ' + ', num_second, ' = ', num_first + num_second)
    elif choice == 2:
        print(num_first, ' - ', num_second, ' = ', num_first - num_second)
    elif choice == 3:
        print(num_first, ' * ', num_second, ' = ', num_first * num_second)
    elif choice == 4:
        if num_second == 0:
            print("You are trying to divide a number by 0")
        else:
            print(num_first, ' / ', num_second, ' = ', num_first / num_second)
    else:
        print("You have input the wrong number")
    
def performCountDown():
    minute = int(input("Input minute = "))
    second = int(input("Input second = "))

    while minute > 0 or second >= 0:
        if second < 0:
            minute -= 1
            second = 59
        if minute == 0 and 0 < second <= 5:
            print(minute, ":", second, " Tik Tok")
        elif minute == 0 and second == 0:
            print(minute, ":", second, " Never Gonna Give You Up")
        else:
            print(minute, ":", second)
        second -= 1


def printBrainF_Pattern():
    x = int(input("Input x = "))
    res, count = x, 1

    while(res != 1):
        count += 1
        res = getBrainF_Pattern(res)
    print(count - 1)

def printAsciiAlphabet():
    for i in range(ord('a'), ord('z')+1):
        print(chr(i), '=', i)
    for i in range(ord('A'), ord('Z')+1):
        print(chr(i), '=', i)    

def getReverseNumber():
    n = int(input("Input n = "))
    res, count_odd, count_even = 0, 0, 0

    while (n > 0):
        reminder = n % 10
        res = res * 10 + reminder
        n = n // 10

        if reminder % 2 == 0:
            count_odd += 1
        else:
            count_even += 1
    print("Even char number = ", count_even)
    print("Odd char number = ", count_odd)
    print("Reversed = ", reminder)

def gradeStudents():
    math = int(input("Input math score = "))
    physics = int(input("Input physics score = "))
    chemistry = int(input("Input chesmitry score = "))
    sum = math + physics + chemistry

    if sum >= 15 and physics >= 4 and math >= 4 and chemistry >= 4:
        print("Pass the test")
        if physics >= 5 and math >= 5 and chemistry >= 5:
            print("Study all the subjects well")
        else:
            print("Study well in a few subjects")
    else:
        print("Fail the test")
    
def getMaxDayOfMonth():
    year = int(input("Year = "))
    month = int(input("Month = "))
    months = [0, 31, 2, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    is_leap = False

    if (year % 4 == 0 and year % 100 != 0) or year % 400:
        print(year, " is a leap year.")
        is_leap = True
    else:
        print(year, " is not a leap year.")

    if month == 2:
        if is_leap:
            print("The number of days in month ", month, ' is ', 29)
        else:
            print("The number of days in month ", month, ' is ', 28)
    else:
        print("The number of days in month ", month, ' is ', months[month])

def mapNumToStr():
    arr_number = ["Zero", "One", "Two", "Three",
                  "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    n = -1
    while n < 0 or n > 9:
        n = int(input("Input 0 <= n <= 9 = "))

    print(n, ' - ', arr_number[n])

def calculateTaxiCost():
    kilometers = int(input("kilometers = "))
    sum = 0
    cost_first, cost_second_to_fifth, cost_general = 15, 13.5, 11
    discount, discount_range = 0.1, 120

    if kilometers == 1:
        sum = cost_first
    elif kilometers <= 5:
        sum = cost_first + cost_second_to_fifth * (kilometers - 1)
    else:
        # kilometers >= 6
        sum = cost_first + cost_second_to_fifth * \
            (5-2+1) + cost_general * (kilometers - 5)
        if kilometers > discount_range:
            sum = sum - sum * discount
    print("Cost {cost}".format(cost=sum))

def calculateProfit():
    choice = input("Input bakning type: (t) for saving account - (v) for current account: ")
    minimum_balance = float(input("Input minimum balance: "))
    end_month_balance = float(input("Input the balance at the end of the month: "))
    current_fine, saving_fine = 10, 25
    rate_saving, rate_current_large, rate_current_small, rate_current_threshold = 0.04, 0.03, 0.05, 5000
        
    if choice == 't':
        # Saving account
        if end_month_balance < minimum_balance:
            print("You have been fined {fine}".format(fine = saving_fine))
            print("Your balance = ", end_month_balance - saving_fine)
        else:
            print("Your balance = ", end_month_balance + end_month_balance * rate_saving)
    elif choice == 'v':
        # Current account
        if end_month_balance < minimum_balance:
            print("You have been fined {fine}".format(fine = current_fine))
            print("Your balance = ", end_month_balance - current_fine)
        else:
            if end_month_balance >= rate_current_threshold:
                print("Your balance = ", end_month_balance + end_month_balance * rate_current_large)
            else:
                print("Your balance = ", end_month_balance + end_month_balance * rate_current_small)
    else:
        print("You have input the wrong code.") 


def mapNumToChar():
    x = -1
    while x > 35 or x < 0:
        x = int(input(" Input 0 <= x <= 35 : "))
    diff = ord('A') - 10

    if x <= 9:
        print(x)
    else:
        print(chr(x + diff))

def solveQuadraticFunction():
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))

    if a == 0:
        # bx + c = 0
        if b == 0:
            if c == 0:
                print("inf")
            if c != 0:
                print("x don't exist")
        else:
            print("x = {res}".format(res = -c/b))
    else:
        # ax**2 + bx + c = 0
        delta = b**2 - 4*a*c
        if delta < 0:
            print("x doesn't exist in R")
        if delta == 0:
            print("x = {res}".format(res = -b/(2*a)))
        if delta > 0:
            print("x1 = {res}".format(res = (-b + delta ** (1/2)) / (2*a) ))
            print("x2 = {res}".format(res = (-b - delta ** (1/2)) / (2*a) ))