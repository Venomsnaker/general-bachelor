from os import system
import json

def readJsonFiles(file_name):
    f_in = open(file_name, "r", encoding="utf-8")
    return json.load(f_in)

def printJsonList(json_file):
    json_clean = json.dumps(json_file, indent=4)
    print(json_clean)

def checkWhetherListHasAnswer(values: list, target):
    for key in values:
        if type(values[key]) == list:
            for sub_answers in values[key]:
                for key_answer in sub_answers:
                    if sub_answers[key_answer] == str(target):
                        return True
        if values[key] == str(target):
            return True
    return False

def printListsWithValues(json_file, target):
    for component_lst in json_file:
        if checkWhetherListHasAnswer(component_lst, target):
            print(component_lst)

def changeAnswerFields(json_file):
    res = []

    for component_lst in json_file:
        curAnswerable = component_lst["answerable"]

        if curAnswerable == 0:
            component_lst["answers"] = "I can’t answer"
        elif curAnswerable == 1:
            component_lst["answers"] = component_lst["answers"][0]
            res.append(component_lst)
    return res

def removeThankyou(json_file):
    res = []

    for component_lst in json_file:
        curQuestion = component_lst["question"]
        curQuestion = curQuestion.lower()
        tksPos = curQuestion.find("thank you")

        if tksPos >= 0:
            curQuestion = curQuestion[:tksPos]
            component_lst["question"] = curQuestion
        res.append(component_lst)
    return res

def removeImage(json_file):
    res = []

    for component_lst in json_file:
        component_lst.pop("image")
        res.append(component_lst)
    return res

def moveResToFile(json_file):
    f_out = open("train1.json", "w")
    json_out = json.dumps(json_file, indent=4)
    f_out.write(json_out)
    f_out.close()

def calculateStringDiff(string1, string2):
    string1 = string1.split(" ")
    string2 = string2.split(" ")
    A = set(string1)
    B = set(string2)
    str_diff = A.symmetric_difference(B)
    return len(str_diff)

def returnSimilarQuestions():
    question = input("Input your question here: ")
    question_lst = []
    f_in = open("train1.json", "r")
    json_file = json.load(f_in)

    for component_lst in json_file:
        question_lst.append(component_lst["question"])

    for question_sub in question_lst[:20]:
        print(question_sub)

    for pos in range(len(question_lst[:20])):
        for idx in range(len(question_lst[:20]) - 1):
            curDiff = calculateStringDiff(question, question_lst[idx])
            nextDiff = calculateStringDiff(question, question_lst[idx + 1])
            if nextDiff < curDiff:
                question_lst[idx], question_lst[idx + 1] = (
                    question_lst[idx + 1],
                    question_lst[idx],
                )
    print("The list of questions similar to your question is: ")
    for question_sub in question_lst[:20]:
        print(question_sub)
    return

def returnFeedback():
    question = input("Input your question here: ")
    answer = input("Input your answer here: ")
    res = []
    f_in = open("train1.json", "r")
    json_file = json.load(f_in)

    for component_lst in json_file:
        curDiff = calculateStringDiff(question, component_lst["answer"])
        if curDiff <= 0.9:
            component_lst["question"] = answer
        else:
            # Add question or something
            res.append(component_lst)
    return res
