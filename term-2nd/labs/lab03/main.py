from os import system

def readFile(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.read()

    print(f_read)
    f_open.close()

def readFirstN(file_name: str):
    n = int(input("Input n here: "))
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()

    for val in f_read[:n+1]:
        print(val.strip())
    f_open.close()

def readLastN(file_name: str):
    n = int(input("Input n here: "))
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    
    for val in f_read[len(f_read)-n:]:
        print(val.strip())
    f_open.close()

def findLongestWords(file_name: str) -> list:
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    dict, words_max_len = [], 0

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == "":
                continue
            if len(word) > words_max_len:
                words_max_len = len(word)
                dict = [word]
            elif len(word) == words_max_len:
                dict.append(word)
    print("The longest words' length is: {len}".format(len = words_max_len))
    print("Longest words are: {values}".format(values = dict))
    f_open.close()
            
def findShortestsWords(file_name: str) -> list:
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    temp, words_min_len = [], float('inf')

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == "":
                continue
            if len(word) < words_min_len:
                words_min_len = len(word)
                temp = [word]
            elif len(word) == words_min_len:
                temp.append(word)
    print("The longest words' length is: {len}".format(len = words_min_len))
    print("Longest words are: {values}".format(values = temp))
    f_open.close()


def countLines(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()

    print("The number of lines is: {number}".format(number = len(f_read)))
    f_open.close()

def getWordsFrequency(file_name: str) -> dict:
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    words_dict = {}

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == "":
                continue
            if word not in words_dict:
                words_dict[word] = 1
            else:
                words_dict[word] += 1

    print("Words and their frequency: ")
    for val in words_dict:
        print(val, ":", words_dict[val])
    f_open.close()
    return words_dict

def getMinFrequencyWords(file_name: str):
    words_dict = getWordsFrequency(file_name)
    words_min_fre, dict = float('inf'), []

    for val in words_dict:
        words_min_fre = min(words_min_fre, words_dict[val])
    for val in words_dict:
        if words_dict[val] == words_min_fre:
            dict.append(val)
    print("Words that appear a min of {min} is: {values}".format(min = words_min_fre, values = dict))

def getMaxFrequencyWords(file_name: str):
    words_dict = getWordsFrequency(file_name)
    words_max_fre, dict = 0, []

    for val in words_dict:
        words_max_fre = max(words_max_fre, words_dict[val])
    for val in words_dict:
        if words_dict[val] == words_max_fre:
            dict.append(val)
    print("Words that appear a max of {max} is: {values}".format(max = words_max_fre, values = dict))

def getWordsEndWithK(file_name: str):
    k = input("Input your k: ")
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    temp = []

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == "":
                continue
            if word[-1] == k:
                temp.append(word)
    print("Words end in {k_value} are: {values}".format(values = temp, k_value = k))
    f_open.close()

def getCharsFrequency(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    chars_dict = {}

    for sentence in f_read:
        sentence = (sentence.strip()).lower()

        for char in sentence:
            if char.isalpha():
                if char in chars_dict:
                    chars_dict[char] += 1
                else:
                    chars_dict[char] = 1
    print("Words with their frequency: {chars_dict}".format(chars_dict = chars_dict))
    f_open.close()

def getWordsFrequencyFromNtoK(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    n = int(input("Input n here: "))
    k = int(input("Input k here: "))
    words_dict = {}

    for sentence in f_read[n-1:k]:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == "":
                continue
            if word not in words_dict:
                words_dict[word] = 1
            else:
                words_dict[word] += 1
    print("Words and their frequency from {n_value} to {k_value} is: ".format(n_value = n, k_value = k))
    for val in words_dict:
        print(val, ":", words_dict[val])
    f_open.close()

def copyFromNtoK(file_name_in: str, file_name_out: str):
    f_open = open(file_name_in, "r")
    f_out = open(file_name_out, "w")

    f_read = f_open.readlines()
    n = int(input("Input n here: "))
    k = int(input("Input k here: "))
    f_out.write("".join(f_read[n-1:k]))

    f_open.close()
    f_out.close()

def getPreviousWordsFrequency(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    target = input("Inpyt your target words here: ")
    dict = {}

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for idx in range(1, len(sentence_lst)):
            if sentence_lst[idx] == target:
                if sentence_lst[idx-1] not in dict:
                    dict[sentence_lst[idx-1]] = 1
                else:
                    dict[sentence_lst[idx-1]] += 1
    print("Previous words with their frequency {words_dict}".format(words_dict = dict))
    f_open.close()
    
def getLinesContainsN(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    target = input("Input your target n here: ")
    trigger = False

    for sentence in f_read:
        sentence_lst = cleanupString(sentence)

        for word in sentence_lst:
            if word == target:
                trigger = True
                print(sentence)
    if trigger == False:
        print("Find None")
    f_open.close()

def replaceInFile(file_name_in: str, file_name_out: str):
    f_open = open(file_name_in, 'r')
    f_read = f_open.readlines()
    target_base = input("Input the word you want to replace here: ")
    target_replace = input("Input the word you wish to replace with here: ")
    res = ""

    for sentence in f_read:
        sentence = sentence.replace(target_base, target_replace)
        res += sentence
    f_open.close()
    f_write = open(file_name_out, 'w')
    f_write.write(res)
    f_write.close()

def insertInLine(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    insert_str = input("Input the string you want to insert here: ")
    insert_idx = int(input("Input the line you want to insert here: "))

    for idx in range(len(f_read)):
        if idx == insert_idx - 1:
            f_read[idx] = f_read[idx] + insert_str
        print(f_read[idx])
    f_open.close()

def deleteLineFromFile(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    n = int(input("Input the line position you one to delete: "))

    for idx in range(len(f_read)):
        if idx == n - 1:
            continue
        print(f_read[idx])
    f_open.close()

def mapNumToWord(file_name: str):
    f_open = open(file_name, 'r')
    f_read = f_open.readlines()
    nums_dict = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five"
                 , 6: "six", 7: "seven", 8: "eight", 9: "nine", 0: "zero"}
    
    for sentence in f_read:
        for val in nums_dict:
            sentence = sentence.replace(str(val), nums_dict[val])
        print(sentence.strip())
    f_open.close()

def cleanupString(f_read_str: str) -> list:
    # Remove \n
    f_read_str = f_read_str.strip()
    # Remove special characters (. , ; etc)
    f_read_str = "".join(c for c in f_read_str if (c.isalpha() or c.isspace() or c == "-" or c == "'"))
    # Convert all to lower case (can be excluded)
    f_read_str = f_read_str.lower()
    # String -> List split with " "
    return f_read_str.split(" ")