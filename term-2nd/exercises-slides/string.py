def countTypes(s: str) -> list:
    count_letter, count_digit, count_special = 0, 0, 0

    for char in s:
        if char.isdigit():
            count_digit += 1
        elif char.isalpha():
            count_letter += 1
        else:
            count_special += 1
    print("The number of letters, digits, and specials are %d, %d, and %d" %
          (count_letter, count_digit, count_special))
    return list(count_letter, count_digit, count_special)

def combineString(s1: str, s2: str) -> str:
    s1_first = s1[:(len(s1)+1)//2]
    s1_second = s1[(len(s1)+1)//2:]
    return s1_first + s2 + s1_second

def sortByLowercase(s: str):
    lowers, uppers = "", ""

    for char in s:
        if char.islower():
            lowers += char
        else:
            uppers += char
    return lowers + uppers

def keepOnlyIntegers(s: str):
    res = ""

    for char in s:
        if char.isdigit():
            res += char
    return res

def cleanLst(lst: list):
    res = []

    for ele in lst:
        if ele is None or len(ele) <= 0:
            continue
        res.append(ele)
    return res

def splitByHyphens(s: str):
    s_lst = s.split("-")
    return "\n".join(s_lst)

def cleanNum(s: str):
    res = ''
    targetIdx = -1

    for char in s:
        if char.isdigit():
            res += char

    for char in res:
        if char == 0:
            targetIdx += 1
        else:
            break
    if targetIdx != -1:
        res = res[targetIdx:]
    return res

def convertEmails():
    inFile = open('teachers.txt', 'r')
    s = inFile.readlines()

    for line in s:
        line = line.strip("\n")
        line = line.lower()
        name_lst = line.split(" ")
        name_res = ''
        for i in range(len(name_lst) - 1):
            name_res += name_lst[i][0]
        name_res += name_lst[len(name_lst) - 1]
        print(name_res)
