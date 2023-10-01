def sortPeopleByHeights(people: list, heights: list):
    n = len(heights)

    for i in range(n):
        flag = False

        for j in range(0, n-i-1):
            if heights[j] > heights[j+1] or (heights[j] == heights[j+1] and people[j] > people[j+1]):
                heights[j], heights[j+1] = heights[j+1], heights[j]
                people[j], people[j+1] = people[j+1], people[j]
                flag = True
        if flag == False:
            break


def combineSortedList(lst_1: list, lst_2: list) -> list:
    res = lst_1 + lst_2
    res.sort()
    return res


def getMaxFre(lst: list) -> list:
    values, frequencies, res = [], [], []

    # Initialize a pseudo dictionary
    for i in range(len(lst)):
        if lst[i] not in values:
            values.append(lst[i])
            frequencies.append(0)
    # Update the map with the frequencies
    for i in range(len(lst)):
        frequencies[values.index(lst[i])] += 1

    max_fre = max(frequencies)

    # Group all the elements that == max_fre
    for i in range(len(frequencies)):
        if frequencies[i] == max_fre:
            res.append(values[i])
    return res


def returnMissing(nums: list, start: int = 0, missing_range: int = 10) -> list:
    res = []

    for i in range(start, missing_range):
        if i not in nums:
            res.append[i]
    return res


def findKthLargest(nums: list, k: int) -> int:
    nums.sort()
    return nums[-k]


def plusOneToList(nums: list) -> list:
    res_int = 0
    res = []

    for i in range(len(nums)):
        res_int *= 10
        res_int += nums[i]
    res_int += 1

    # Convert res_int to res (int -> list)
    while res_int > 0:
        res.append(res_int % 10)
        res_int = res_int // 10
    # Flip back the list
    res = res[::-1]
    return res


def returnLargestCombination(nums: list) -> str:
    if len(nums) == 1:
        return str(nums[0])

    # nums[int] -> nums[string]
    for i in range(len(nums)):
        nums[i] = str(nums[i])

    # Sort the array
    for i in range(len(nums)):
        for j in range(1+i, len(nums)):
            if nums[j] + nums[i] > nums[i] + nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
    res = ''.join(nums)
    return res


def flipInvertMatrix(matrix: list):
    n = len(matrix[0])

    # Traverse through the matrix left to right, top to bottom
    for i in range(n):
        # Invert each lines of the matrix
        matrix[i] = matrix[i][::-1]

        # 0 -> 1; 1 -> 0
        for j in range(n):
            if matrix[i][j] == 0:
                matrix[i][j] = 1
            else:
                matrix[i][j] = 0


def returnLargestSubarrays(nums: list, subarray_size: int) -> list:
    max_sum = 0
    res = []

    # Getting the max sum
    for i in range(len(nums) - subarray_size + 1):
        max_sum = max(max_sum, sum(nums[i:i+subarray_size]))

    # Initialize res with all subarrays with sum == max_sum
    for i in range(len(nums) - subarray_size + 1):
        curSum = sum(nums[i:i+subarray_size])
        if curSum == max_sum:
            res.append(nums[i:i+subarray_size])
    return res

def returnCouples(nums: list, target: int) -> list:
    seen, res = [], []

    for val in nums:
        if val == target/2 and val not in seen:
            if nums.count(val) >= 2:
                res.append([val, val])
                seen.append(val)

        if target - val in nums and target - val not in seen:
            res.append([val, target - val])
            seen.append(val)
    return res


def returnTriples(nums: list, target: int) -> list:
    res = []

    for i in range(len(nums)):
        for j in range(i, len(nums)):
            for k in range(j, len(nums)):
                if nums[i] + nums[j] + nums[k] == target:
                    res.append([nums[i], nums[j], nums[k]])
    return res

def checkIfCoupleExits(nums: list, target: int) -> bool:
    for val in nums:
        if target - val not in nums:
            return False
    return True
