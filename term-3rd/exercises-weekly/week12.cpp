#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sortUnderlineText()
{
    string input;

    cout << "Input your string: ";
    getline(cin, input);

    int n = input.size();
    string underline(n, ' ');
    int underline_pos;

    cout << "Please input all the underline position (start from 0 from left - input outside the string length to stop): " << endl;

    do
    {
        cin >> underline_pos;
        if (underline_pos >= 0 && underline_pos < input.size())
        {
            underline[underline_pos] = '-';
        }
    } while (underline_pos >= 0 && underline_pos < input.size());
    cin.ignore();
    cout << "This is the string you have just input: " << endl;
    cout << input << endl;
    cout << underline << endl;

    for (int i = 0; i < n; i++)
    {
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if ((input[j] > input[idx]) || (input[j] == input[idx] && underline[j] > underline[idx]))
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swap(input[i], input[idx]);
            swap(underline[i], underline[idx]);
        }
    }
    cout << "Sorted: " << endl;
    cout << input << endl;
    cout << underline << endl;
}

void countSort(vector<int> &arr)
{
    cout << "Using CountSort: " << endl;
    vector<int> count(100), output(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < 100; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    sortUnderlineText();
    vector<int> testArr = {3, 77, 45, 65, 2, 5, 6, 9, 45};
    for (auto val: testArr) {
        cout << val << " ";
    }
    cout << endl;
    countSort(testArr);
    for (auto val: testArr) {
        cout << val << " ";
    }
    return 0;
}