# This script contains codes for the on-class exercises
import numpy as np

def getMaxDiagonal(a: np.array):
    print(a)
    diagonal_main = a.diagonal()
    diagonal_sub = np.fliplr(a).diagonal()
    return max(np.sum(diagonal_main), np.sum(diagonal_sub))

def convertIntToRoman(self, num: int) -> str:
    # Creating Dictionary for Lookup
    num_map = {
        1: "I",
        5: "V",    4: "IV",
        10: "X",   9: "IX",
        50: "L",   40: "XL",
        100: "C",  90: "XC",
        500: "D",  400: "CD",
        1000: "M", 900: "CM",
    }
    r = ''
    
    for n in [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]:
        # If n in list then add the roman value to result variable
        while n <= num:
            r += num_map[n]
            num-=n
    return r