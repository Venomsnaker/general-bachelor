def printList(arr):
    if len(arr) == 0:
        return 0
    return arr[-1] + printList(arr[:-1])

def checkAscending(arr):
    if len(arr) <= 1:
        return True 
    
    if arr[-1] <= arr[-2]:
        return False
    return checkAscending(arr[:-1])

def isPalindrome(arr):
    if len(arr) <= 1:
        return True

    if arr[-1] != arr[0]:
        return False
    return isPalindrome(arr[1:-1])

def binarySearch(arr, target, l, r):
    if l > r:
        return -1

    mid = (l + r) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binarySearch(arr, target, mid + 1, r)
    else:
        return binarySearch(arr, target, l, mid - 1)
    
def solveHanoiTower(n, source, aux, dest):
    if n == 1:
        print("Move " + str(n) + " from " + str(source) + " to " + str(dest))
    else:
        solveHanoiTower(n-1, source, dest, aux)
        print("Move " + str(n) + " from " + str(source) + " to " + str(dest))
        solveHanoiTower(n-1, aux, source, dest)

def solveKnapsack(weights, prices, capacity, n):
    if n == 0 or capacity == 0:
        return 0

    if weights[n-1] > capacity:
        return solveKnapsack(weights, prices, capacity, n - 1)
    return max( prices[n-1] + solveKnapsack(weights, prices, capacity - weights[n-1], n - 1), 
               solveKnapsack(weights, prices, capacity, n - 1))

def sumOfDigit(num):
    if num <= 0:
        return 0
    return num % 10 + sumOfDigit(num // 10)

def maxDigit(num):
    if num <= 0:
        return 0
    return max(num % 10, maxDigit(num // 10))
    
def isPrime(num, cur):
    if num <= 1:
        return True
    
    if num % cur == 0:
        return False
    return isPrime(num, cur - 1)
