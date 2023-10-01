import numpy as np

def turnOddToMinusOne(arr):
    arr[arr % 2 == 1] = -1
    return arr

def turn1DTo2D(arr):
    n = len(arr) // 2
    arr = arr.reshape(n,n)
    return arr

def returnRandomizeIntList():
    n = int(input("Input the length of your randomized array: "))
    start = int(input("Input the start pos: "))
    end = int(input("Input the end pos: "))
    return np.random.randint(start, end, n, dtype=int)

def extractColumnK(arr):
    n = int(input("Input the column you one to extract: "))

    arr = arr.T
    if 0 <= n and n - 1 <= len(arr[0]):
        return arr[n-1]
    return []

def returnUniqueRows(arr):
    n = len(arr[0])
    res = []

    for row in arr:
        duplicateds = (row[row == row[0]])
        if len(duplicateds) == n:
            continue
        res.append(row)
    return res

def formatDaysInMonth():
    month = int(input("Input the month here: "))
    year = int(input("Input the year here: "))
    year_next = year
    month_next = month - 1

    if month_next == 12:
        month_next = 1
        year_next += 1

    if month_next >= 10:
        time_prev = str(year_next) + '-' + str(month_next)
    else: time_prev = str(year_next) + '-0' + str(month_next)

    if month >= 10:
        time_now = str(year) + '-' + str(month)
    else: time_now = str(year) + '-0' + str(month)
    return np.arange(time_prev, time_now, dtype = 'datetime64[D]')


def getSumFrom20To50(arr):
    arr[ (arr < 20) | (arr > 50) ] = 0
    print(arr)
    return np.sum(arr)