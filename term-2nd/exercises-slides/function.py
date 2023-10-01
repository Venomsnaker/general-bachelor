def isPrime(n: int) -> bool:
    if n < 2:
        return False
    
    if n % 2 == 0 and n != 2:
        return False
    
    for i in range(3, int(n/2 + 2), 2):
        if n % i == 0:
            return False
    return True

def findPrimeLarger(n: int) -> int:
    while(True):
        n += 1
        if isPrime(n):
            return n
        
def findGCD(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a

def simplifyFrac(numerator: int, denominator: int):
    c = findGCD(numerator, denominator)
    numerator /= c
    denominator /= c

    if denominator < 0:
        return -numerator, -denominator
    else:
        return numerator, denominator
    
def addOddsOfLst(lst: list):
    i = 0

    while(i < len(lst) - 1):
        if lst[i] % 2 != 0 and lst[i+1] % 2 != 0:
            lst.insert(i+1, int(lst[i] + lst[i+1]))
        i = i + 1

def returnAllOccurrences(element: int, lst: list) -> list:
    res = []

    for i in range(len(lst)):
        if element == lst[i]:
            res.append(i)
    return res

def returnAllPrime(lst: list) -> list:
    count = 0

    for i in lst:
        if isPrime(i):
            count += 1
    return count

def sortSelection(lst: list):
    for i in range(len(lst) - 1):
        minIdx = i

        for j in range(i, len(lst)):
            if lst[j] < lst[minIdx]:
                minIdx = j
        if minIdx != i:
            lst[i], lst[minIdx] = lst[minIdx] , lst[i]

def sortBubble(lst: list):
    for _ in range(len(lst) - 1):
        for i in range(len(lst) - 1):
            if lst[i] > lst[i+1]:
                lst[i], lst[i+1] = lst[i+1], lst[i]     

def sortOler(lst):
    for _ in range(len(lst) - 1):
        for i in range(len(lst) - 1):
            if lst[i] % 2 == 0 and lst[i+1] % 2 != 0:
                lst[i], lst[i+1] = lst[i+1], lst[i]

def checkSymmetrical(lst) -> bool:
    for i in range(int(len(lst) / 2)):
        if lst[i] != lst[len(lst) - i - 1]:
            return False
    return True