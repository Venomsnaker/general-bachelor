#include <bits/stdc++.h>
using namespace std;

void Example()
{
    string food = "Pizza";
    string *ptr = &food;

    cout << food << "-" << ptr << "-" << *ptr << endl;
    food = "Hotdog";
    cout << food << "-" << ptr << "-" << *ptr << endl;
}

int main()
{
    Example();
    return 0;
}