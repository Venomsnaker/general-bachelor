import numpy as np
import json

def getStudentsRankByScores(arr):
    if len(arr) <= 0:
        return []

    arr_sorted = sorted(arr, reverse=True)
    arr_ranks = [0 for i in range(len(arr))]
    arr_ranks[0] = 1

    for i in range(1, len(arr_sorted)):
        if arr_sorted[i] == arr_sorted[i-1]:
            arr_ranks[i] = arr_ranks[i-1]
        else:
            arr_ranks[i] = arr_ranks[i-1] + 1
    for i in range(len(arr)):
        pos = arr_sorted.index(arr[i])
        arr[i] = arr_ranks[pos]
    return arr

def readMatrixes(filePath):
    f_in = open(filePath, "r")
    f_out = open("output.txt", "w")

    firstLine = f_in.readline().split(",")
    a_row, a_col = int(firstLine[0].strip()), int(firstLine[1].strip())

    secondLine = f_in.readline().split(",")
    b_row, b_col = int(secondLine[0].strip()), int(secondLine[1].strip())

    a = [[0 for x in range(a_col)] for y in range(a_row)]
    b = [[0 for x in range(b_col)] for y in range(b_row)]

    for i in range(a_row):
        line = f_in.readline().split(",")
        for j in range(a_col):
            a[i][j] = int(line[j].strip())

    for i in range(b_row):
        line = f_in.readline().split(",")
        for j in range(b_col):
            b[i][j] = int(line[j].strip())

    a = np.array(a)
    b = np.array(b)

    c = a @ b
    d = np.transpose(a) @ b

    f_out.write(str(c))
    f_out.write("\n \n")
    f_out.write(str(d))
    f_in.close()
    f_out.close()

def maxSubMatrix(matrix, i, j):
    m, n = len(matrix), len(matrix[0])
    res = []
    maxVal = float('-inf')

    for row_pos in range(m - i + 1):
        for col_pos in range(n - j + 1):
            temp = np.sum(matrix[row_pos: row_pos + i, col_pos: col_pos + j])
            if temp > maxVal:
                maxVal = temp
                res = matrix[row_pos: row_pos + i, col_pos: col_pos + j]
    return res

def createMatrix1to25(n):
    return np.random.randint(1, 26, (n,n))

def flipMatrixBySubHorizontal(arr):
    arr_flip = arr[:,::-1]
    arr_flip_t = np.transpose(arr_flip)
    res = arr_flip_t[:, ::-1]
    return res

def getMaxRow(arr):
    res = [0 for i in range(len(arr[0]))]
    count = 0
    for i in range(len(arr[0])):
        temp = 0
        for j in range(len(arr)):
            temp = max(temp, arr[j][i])
        res[count] = temp
        count += 1
    return res

def betweenCircleAndRectangle(points, a, b, c):
    temp = []
    a_x, a_y = a[0], a[1]
    b_x, b_y = b[0], b[1]
    c_x, c_y = c[0], c[1]

    rectangle_mid_x = (a_x + b_x) / 2
    rectangle_mid_y = (a_y + b_y) / 2

    diff_x = c_x - rectangle_mid_x
    diff_y = c_y - rectangle_mid_y
    circle_r = sqrt(diff_x ** 2 + diff_y ** 2)

    for point in points:
        point_diff_x = c_x - point[0]
        point_diff_y = c_y - point[1]
        point_diff = sqrt(point_diff_x ** 2 + point_diff_y ** 2)

        if a_x <= point[0] <= b_x and b_y <= point[1] <= a_y and point_diff <= circle_r :
            temp.append(point)
    return temp

if __name__ == '__main__':
    print("Cau 1")
    input_1 = [9,3,2,5,4,7,8,7]
    print("Input: {input}".format(input = input_1))
    print("Output: ", getStudentsRankByScores(input_1))
    print("Cau 2")
    print("Check input.txt, output.txt")
    readMatrixes("test.txt")
    print("Cau 3")
    input_2 = np.arange(20).reshape(5, 4)
    i = 3
    j = 2
    print("Input: ", input_2, i ,j, sep = " ")
    print(maxSubMatrix(input_2, i, j))
    print("Cau 4")
    a = createMatrix1to25(3)
    print(a)
    print()
    b = flipMatrixBySubHorizontal(a)
    print(b)
    print()
    c = getMaxRow(b)
    print(c)
    print("Cau 5")
    """
    Check whether the point fall into the triangle and the circle
    """
