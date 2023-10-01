#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void solveTowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    solveTowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    solveTowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int gerMaxFrequency(int arr[], int n)
{
    map<int, int> traversed = {};

    for (int i = 0; i <= n; i++)
    {
        traversed[arr[i]] += 1;
    }

    int maxFre = 0;

    for (const auto &[key, value] : traversed)
    {
        if (value > maxFre)
        {
            maxFre = value;
        }
    }
    return maxFre;
}

void getArrRange(float arr[], int n)
{
    // Get the [-x,x] that contains the whole array
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
    }

    float res;

    if (abs(max) > abs(min))
    {
        res = abs(max);
    }
    else
    {
        res = abs(min);
    }
    cout << "[ " << -res << "," << res << " ]" << endl;
}

void writeFile(string filePath)
{
    ofstream f_out(filePath);

    if (f_out.is_open())
    {
        // f_out << "Something \n";
    }
    f_out.close();
    return;
}

void readFile(string filePath)
{
    string temp;
    ifstream f_in(filePath);

    while (getline(f_in, temp))
    {
        cout << temp;
    }
    f_in.close();
    return;
}

double getNPowerOfX(double x, double n)
{
    double res = 1;

    for (double i = 1; i <= n; i++)
    {
        res *= x;
    }
    return res;
}

void getDivisorsFormula(int a, int b)
{
    int min = (a < b) ? a : b;
    double gcd;

    // Get gcd
    while (min > 0)
    {
        if ((a % min == 0) && (b % min == 0))
        {
            gcd = min;
            break;
        }
        min = min - 1;
    }

    if (gcd == 0)
    {
        gcd = (a == 0) ? b : a;
    }

    // Get the formula
    double curPos = 1;

    while (true)
    {
        double remainder = ((gcd - a * curPos) / b);
        if (remainder == floor(remainder))
        {
            cout << curPos << " " << remainder;
            break;
        }

        remainder = ((gcd - a * -curPos) / b);
        if (remainder == floor(remainder))
        {
            cout << -curPos << " " << remainder;
            break;
        }
        curPos += 1;
    }
}

void printAtoZ()
{
    int charCode = int('A');

    while (charCode <= int('Z'))
    {
        cout << char(charCode) << " ";
        charCode += 1;
    }
}

void printASCII()
{
    int charCode = 0;

    while (charCode <= int('Z'))
    {
        cout << charCode << " " << char(charCode) << endl;
        charCode += 1;
    }
}

void printEmptyRectangle(int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        if (i == 0 || i == height - 1)
        {
            for (int j = 0; j < width; j++)
            {
                cout << "* ";
            }
        }
        else
        {
            cout << "* ";
            for (int j = 0; j < width - 2; j++)
            {
                cout << "  ";
            }
            cout << "* ";
        }
        cout << endl;
    }
}

void printEmptyPyramid(int height)
{
    int startCounter = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height * 2 - 1 - startCounter; j++)
        {
            cout << " ";
        }

        if (i == 0 || i == height - 1)
        {
            for (int j = 0; j < startCounter; j++)
            {
                cout << "* ";
            }
        }
        else
        {
            cout << "* ";
            for (int j = 0; j < startCounter - 2; j++)
            {
                cout << "  ";
            }
            cout << "* ";
        }
        startCounter += 2;
        cout << endl;
    }
}

void printPascalPyramid(int row_num)
{
    for (int n = 1; n <= row_num; n++)
    {
        for (int r = 1; r < row_num - n + 1; r++)
            cout << "  ";

        int val = 1;

        for (int r = 1; r <= n; r++)
        {
            cout << val << "   ";

            val = val * (n - r) / r;
        }
        cout << endl;
    }
}

double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(abs(y1 - y2), 2) + pow(abs(x1 - x2), 2));
}

void solveLinearEquationPair(int x1, int y1, int x2, int y2)
{
    // ax + b = 0
    if (x1 - x2 == 0)
    {
        cout << "x = " << x1 << endl;
        return;
    }
    if (y1 - y2 == 0)
    {
        cout << "y = " << y1 << endl;
    }
    int slope = (y2 - y1) / (x2 - x1);
    cout << "Formula: " << slope << "x + " << -slope * x1 + y1 << endl;
}

void getTriangleCentroid(int x1, int y1, int x2, int y2, int x3, int y3)
{
    cout << "The Centroid Pos: (" << (x1 + x2 + x3) / 3 << "," << (y1 + y2 + y3) / 3 << ')' << endl;
}

int getAreaWithPos(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
}

void specifyPercision(long double num, int accuracy)
{
    cout << setprecision(accuracy + 1) << num << endl;
}

void sortArrRows(int arr[4][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int targetIndex = j;
            for (int k = j; k < col; k++)
            {
                if (arr[i][k] > arr[i][targetIndex])
                {
                    targetIndex = k;
                }
            }
            if (targetIndex != j)
            {
                int temp = arr[i][targetIndex];
                arr[i][targetIndex] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
}

void DeleteMatrixCol(int matrix[99][99], int row, int col, int targetCol)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (j >= targetCol)
            {
                matrix[i][j] = matrix[i][j + 1];
            }
        }
    }
}

void standardizeText(string s)
{
    int i = 0;

    // Remove whitespaces
    // Front
    while (s[0] == ' ')
    {
        for (i = 0; i < sizeof(s) - 1; i++)
        {
            s[i] = s[i + 1];
        }
        s[sizeof(s) - 1] = '\0';
    }

    // Back
    while (s[sizeof(s) - 1] == ' ')
    {
        s[sizeof(s) - 1] = '\0';
    }

    // Middle
    i = 0;
    while (i < sizeof(s) - 1)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            for (int j = i + 1; j < sizeof(s) - 1; j++)
            {
                s[j] = s[j + 1];
            }
            s[sizeof(s) - 1] = '\0';
        }
        else
            i++;
    }

    // Turn every characters to lowercase
    for (int i = 0; i < sizeof(s) - 1; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }

    // Change the first character to uppercase
    s[0] = s[0] - 32;

    // The rest
    for (int i = 0; i < sizeof(s) - 1; i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = s[i + 1] - 32;
        }
    }
    cout << s;
}

bool IsPalindrome(string s)
{
    int length = (int)s.length();
    for (int i = 0; i < length / 2; i++)
    {
        if (s[i] != s[length - 1 - i])
        {
            return false;
        }
    }
    return true;
}

string formatNumber(int number)
{
    string result = "";
    string tmp = to_string(number);
    int count = 0;

    for (int i = (int)tmp.length() - 1; i >= 0; i--)
    {
        count++;
        result = tmp[i] + result;
        if (count % 3 == 0 && i - 1 >= 0 && tmp[i - 1] != '-')
            result = ',' + result;
    }
    return result;
}

bool checkCorrectBrackets(string s)
{
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (count < 1)
            {
                return false;
            }
            count -= 1;
        }
        else
        {
            count += 1;
        }
    }

    return (count == 0) ? true : false;
}

string checkDuplicatedSubArray(string s)
{
    string pattern;
    string chosenPattern;
    int patternLength = 1;
    pattern += s[0];

    // Get the pattern
    for (int i = 1; i < s.length(); i++)
    {
        if (pattern.compare(s.substr(i, patternLength)) == 0)
        {
            chosenPattern = pattern;
            break;
        }
        pattern += s[i];
        patternLength += 1;
    }

    // Check if the pattern repeat
    if (patternLength == s.length())
    {
        return "false";
    }

    for (int i = 0; i < s.length(); i += patternLength)
    {
        if (pattern.compare(s.substr(i, patternLength)) != 0)
        {
            return "false";
        }
    }

    return chosenPattern;
}