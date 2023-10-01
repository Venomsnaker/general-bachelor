import json

def findRepeated(tup):
    res = []

    for val in tup:
        if val not in res and tup.count(val) > 1:
            res.append(val)
    return res

def findSecondLargest(tup):
    tup_lst = list(tup)
    tup_lst.sort()
    return tup_lst[-2]

def isPrime(num):
    if num == 2:
        return True

    if num % 2 == 0 or num <=1 :
        return False
    
    for i in range(3, len(num)/2+2, 2):
        if num % i == 0:
            return False
    return True

def countPrime(tup):
    count = 0
    
    for val in tup:
        if isPrime(val):
            count += 1
    return count

def insertToTuple(tup, ele, pos):
    return tup[:pos] + (ele,) + tup[pos:]

def removeEmptyTuple(lst):
    res = []

    for tup in lst:
        if len(tup) == 0:
            continue
        res.append(tup)
        res.pop()
    return res

def removeIntersection(set1, set2):
    intersection = set1 & set2
    set1 = set1 - intersection
    set2 = set2 - intersection
    return set1, set2

def returnSubsets():
    se = {1,2,3}

    for val in se:
        print(val, se - val, )

def printSubsets(base):
    res = []
    subsets = list()
    base = list(base)

    def helper(base, subsets, index, res):
        res.append(set(subsets))

        for i in range(index, len(base)):
            subsets.append(base[i])
            helper(base, subsets, i + 1, res)
            subsets.pop(-1)
        return

    helper(base, subsets, 0, res)
    return res
    
def findDifferences(a, b):
    return ((a^b)&a)

def readVotes():
    f_open = open("input.txt", "r")
    f_read = f_open.readline()
    f_read = f_read.strip()
    votes_lst = f_read.split("/")
    print(votes_lst)
    my_dict = {}

    for vote in votes_lst:
        if vote not in my_dict:
            my_dict[vote] = 1
        else:
            my_dict[vote] += 1
    
    maxVote = max(list(my_dict.values()))
    res = []

    for val in my_dict:
        if my_dict[val] == maxVote:
            res.append(val)
    res.sort()
    return res


def sortDictionaryWithKeys():
    my_dict = {'a': 1, 'b': 3, 'c': 4, 'd': 2}
    print(dict(sorted(my_dict.items())))
    print(dict(sorted(my_dict.items(), key=lambda item: item[1])))

def loadJson():
    inFile = open('input-json.json', 'r')
    data = json.load(inFile)
    maxScore = 0
    res = ''

    for student in data.values():
        print(student['score'])
        if student['score'] > maxScore:
            maxScore = student['score']
            res = student['name']
    print(res)