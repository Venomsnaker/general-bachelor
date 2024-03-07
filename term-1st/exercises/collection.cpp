#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// 2022 November 18
void swapVariables()
{
    int x = 0, y = 0;

    cout << "Input x: ";
    cin >> x;
    cout << "Input y: ";
    cin >> y;

    x = x + y;
    y = x - y;
    x = x - y;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

void checkTriangleType()
{
    int largest = 0, middle = 0, smallest = 0;

    cout << "Input largest: ";
    cin >> largest;
    cout << "Input middle: ";
    cin >> middle;
    cout << "Input smallest: ";
    cin >> smallest;

    if (largest >= (middle + smallest))
    {
        cout << "Doesn't form a triangle." << endl;
    }
    else
    {
        if (largest == middle && middle == smallest)
        {
            cout << "Equilateral Triangle." << endl;
        }
        else
        {
            if (largest == middle || middle == smallest)
            {
                cout << "Isosceles Triangle." << endl;
            }
            else
            {
                cout << "Just a Triangle." << endl;
            }
        }
    }
}

void printMonthMaxDate()
{
    int month = 0, year = 0;

    do
    {
        cout << "Input the year: ";
        cin >> year;
    } while (year <= 0);
    do
    {
        cout << "Input the month: ";
        cin >> month;
    } while (month <= 0 && month >= 13);

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        cout << "31/" + to_string(month) + "/" + to_string(year) << endl;
    }
    else
    {
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                cout << "29/" + to_string(month) + "/" + to_string(year) << endl;
            }
            else
            {
                cout << "28/" + to_string(month) + "/" + to_string(year) << endl;
            }
        }
        else
        {
            cout << "30/" + to_string(month) + "/" + to_string(year) << endl;
        }
    }
}

void printCloseDate()
{
    int month = 0, year = 0, date = 0;

    cout << "Input year: " << endl;
    cin >> year;
    cout << "Input month: " << endl;
    cin >> month;
    cout << "Input date: " << endl;
    cin >> date;

    if (date == 1)
    {
        // Previous month has 30 days
        if (month == 5 || month == 7 || month == 10 || month == 12)
        {
            cout << "30/" + to_string(month - 1) + "/" + to_string(year) << endl;
        }
        else
        {
            // Previous month has 31 days
            if (month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
            {
                // January
                if (month == 1)
                {
                    cout << "31/12/" + to_string(year - 1) << endl;
                }
                else
                {
                    cout << "31/" + to_string(month - 1) + "/" + to_string(year) << endl;
                }
            }
            else
            {
                // March
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                {
                    cout << "29/2/" + to_string(year) << endl;
                }
                else
                {
                    cout << "28/2/" + to_string(year) << endl;
                }
            }
        }
        cout << to_string(date + 1) + to_string(month) + "/" + to_string(year) << endl;
    }
    else
    {
        // Date == max of month
        if ((month == 2 && (((date == 28) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) || date == 29)) || (date == 31 || date == 30))
        {
            cout << to_string(date - 1) + to_string(month) + "/" + to_string(year) << endl;
            // December
            if (month == 12)
            {
                cout << "1/1/" + to_string(year + 1) << endl;
            }
            else
            {
                cout << "1/" + to_string(month + 1) + "/" + to_string(year) << endl;
            }
        }
        else
        {
            // The rest
            cout << to_string(date - 1) + to_string(month) + "/" + to_string(year) << endl;
            cout << to_string(date + 1) + to_string(month) + "/" + to_string(year) << endl;
        }
    }
}

// 2022 November 29
void checkPalindrome()
{
    int reverse, curDigit, n;

    cout << "Input n: ";
    cin >> n;

    do
    {
        curDigit = n % 10;
        reverse = reverse * 10 + curDigit;
        n = n / 10;
    } while (n > 0);

    if (reverse == n)
    {
        cout << n << " is a Palindrome." << endl;
    }
    else
    {
        cout << n << " isn't a Palindrome." << endl;
    }
}

void checkSquareNumber()
{
    bool flag = false;
    int n;

    cout << "Input n: ";
    cin >> n;

    for (int i = 1; i <= n / 2; i++)
    {
        if (n == (i * i))
        {
            flag = true;
        }
    }

    if (flag)
    {
        cout << n << " is a Square Number." << endl;
    }
    else
    {
        cout << n << " isn't a Square Number." << endl;
    }
}

void checkPrimeNumber()
{
    bool flag = true;
    int n;

    cout << "Input n: ";
    cin >> n;

    if (n <= 1)
    {
        flag = false;
    }
    for (int i = 2; i <= n / 2 + 2; i++)
    {
        if (n % i == 0)
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << n << " is a Prime Number." << endl;
    }
    else
    {
        cout << n << " isn't a Prime Number." << endl;
    }
}

void checkTrend()
{
    bool flag_ascend = true, flag_descend = true;
    int prevDigit, curDigit, n;

    if (n < 10)
    {
        cout << n << " has only 1 digit." << endl;
    }
    else
    {
        prevDigit = n % 10;
        n = n / 10;

        while (n > 0)
        {
            curDigit = n % 10;
            if (curDigit > prevDigit)
            {
                flag_descend = false;
            }
            if (curDigit < prevDigit)
            {
                flag_ascend = false;
            }
            prevDigit = curDigit;
            n = n / 10;
        }

        cout << "Ascend: " << flag_ascend << endl;
        cout << "Descend: " << flag_descend << endl;
    }
}

void printSumToN()
{
    int sum, n;

    cout << "Input n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "Sum from 1 to n: " << sum << endl;
}

void printProduct()
{
    unsigned long product = 1;
    int n;

    cout << "Input n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    cout << n << "! == " << product << endl;
}

void printGCD()
{
    int min, max, divisor;
    cout << "Input the 2 numbers: ";
    cin >> min >> max;

    // Making sure min is the min value
    if (max < min)
    {
        max = max + min;
        min = max - min;
        max = max - min;
    }

    // Find the largest divisor
    for (int i = min; i >= 1; i -= 1)
    {
        if (max % i == 0 && min % i == 0)
        {
            divisor = i;
            break;
        }
    }
    cout << "GCD: " << divisor << endl;
}

void printFibonacci()
{
    int n;

    do
    {
        cout << "Input n: ";
        cin >> n;
    } while (n <= 0);

    cout << n << " first numbers from Fibonacci: ";

    if (n <= 2)
    {
        while (n > 0)
        {
            cout << "1 ";
            n -= 1;
        }
    }
    else
    {
        cout << "1 1 ";
        n -= 2;
        int prevDigit_two = 1, prevDigit_one = 1, curDigit = 2;

        while (n > 0)
        {
            curDigit = prevDigit_one + prevDigit_two;
            cout << curDigit << " ";
            prevDigit_two = prevDigit_one;
            prevDigit_one = curDigit;
            n -= 1;
        }
    }
}

// 2022 December 15
void checkPerfectNumber()
{
    int n = 0, sum = 0;

    cout << "Input the number: ";
    cin >> n;

    // Calculating the sum of divisors
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    if (sum == n)
    {
        cout << n << " La so hoan hao." << endl;
    }
    else
    {
        cout << n << " Khong la so hoan hao." << endl;
    }
}

// 2022 December 31
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findInArr(int arr[], int n, int target)
{
    int res = -1;

    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            res = i;
            break;
        }
    }

    if (res != -1)
    {
        cout << "The target is located at pos: " << res + 1 << endl;
    }
    else
    {
        cout << "The target isn't in the array." << endl;
    }
}

int findInArrBinary(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

void sortBubble(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printArr(arr, n);
    int res = findInArrBinary(arr, n, target);

    if (res != -1)
    {
        cout << "The target is located at pos: " << res + 1 << endl;
    }
    else
    {
        cout << "The target isn't in the array." << endl;
    }
}

void getSumOfArray(int arr1[], int arr2[], int arr3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
    printArr(arr3, n);
    cout << endl;
}

int getFibonanci(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return getFibonanci(n - 1) + getFibonanci(n - 2);
}

long getFactorial(int n)
{
    long res = 1;

    for (long i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

// 2023 January 05
struct Data
{
    string name;
    int year = INT_MAX;
    int month = 13;
    int day = 32;
} curData;

void readDates()
{
    struct Data curData;
    string line;
    ifstream file("dates.txt");
    string contents((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    istringstream f(contents);

    while (getline(f, line))
    {
        stringstream ss(line);
        string prevWord, lastWord, newWord;

        while (ss >> newWord)
        {
            prevWord = lastWord;
            lastWord = newWord;
        }

        int curDay = stoi(lastWord.substr(0, 1));
        int curMonth = stoi(lastWord.substr(3, 4));
        int curYear = stoi(lastWord.substr(6, 9));
        
        if (curYear < curData.year || (curYear == curData.year && curMonth < curData.month) || (curYear == curData.year && curMonth == curData.month && curDay < curData.day))
        {
            curData = {prevWord, curYear, curMonth, curDay};
        }
    }
    cout << curData.name << " " << 2022 - curData.year << endl;
    file.close();
}

void print2dArray(int arr[100][100], int maxCLen, int maxRLen)
{
    for (int i = 0; i < maxCLen; i++)
    {
        for (int j = 0; j < maxRLen; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void get2dArrayRound(int arr[100][100], int target, int maxRLen)
{
    cout << target << " round: ";
    for (int i = 0; i < maxRLen; i++)
    {
        cout << arr[target - 1][i] << " ";
    }
    cout << endl;
}

void get2dArrayColumn(int arr[100][100], int target, int maxCLen)
{
    cout << target << " col: ";
    for (int i = 0; i < maxCLen; i++)
    {
        cout << arr[i][target - 1] << " ";
    }
    cout << endl;
}

void traverse2dArrayRightDiagonal(int arr[100][100], int curR, int curC, int maxCLen, int maxRLen)
{
    while ((curR < maxRLen) && (curC < maxCLen))
    {
        cout << arr[curR - 1][curC - 1] << " ";
        curR += 1;
        curC += 1;
    }
    cout << endl;
}

void traverse2dArrayLeftDiagonal(int arr[100][100], int curR, int curC, int maxRLen)
{
    while ((curR < maxRLen) && (curC > 0))
    {
        cout << arr[curR - 1][curC - 1] << " ";
        curR += 1;
        curC -= 1;
    }
    cout << endl;
}

void return2dArrayCorners(int arr[100][100], int maxRLen, int maxCLen)
{
    cout << "Up Left: " << arr[0][0] << endl;
    cout << "Down Left: " << arr[maxRLen - 1][0] << endl;
    cout << "Up Right: " << arr[0][maxCLen - 1] << endl;
    cout << "Down Right: " << arr[maxRLen - 1][maxCLen - 1] << endl;
}

void swapLocations(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortInsertion(int arr[], int len)
{
    printArr(arr, len);
    int key;

    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printArr(arr, len);
}

void sortSelection(int arr[], int len)
{
    printArr(arr, len);
    int minIndex = 0;

    for (int i = 0; i < len; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapLocations(&arr[minIndex], &arr[i]);
        }
    }
    printArr(arr, len);
}

int main()
{
    int code = -1, repeat = 1;
    string answer = "";

    while (repeat)
    {
        system("cls");
        cout << "0: Shut Down" << endl;

        do
        {
            cout << "Input the number corresponding with the function you want to use:" << endl;
            cin >> code;
        } while (code < 0 || code > 999);

        switch (code)
        {
        case 0:
            break;
        default:
            break;
        }

        do
        {
            cout << "Do you wish to continue? ('y'/'n')" << endl;
            cin >> answer;
        } while (answer != "y" && answer != "n");
        if (answer == "n")
        {
            repeat = 0;
        }
    }
    return 0;
}
