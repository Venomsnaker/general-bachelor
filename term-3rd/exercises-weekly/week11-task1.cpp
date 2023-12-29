#include <iostream>
#include <time.h>
using namespace std;

long long getNumberSequenceRecursive(int n, int a) {
    if (n == 1) return a;
    if (n == 2) return 18 * a * a + 10;
    return 18 * getNumberSequenceRecursive(n - 1, a) + 10 * getNumberSequenceRecursive(n - 2, a);
}

long long getNumberSequenceIterative(int n) {
    if (n < 1) {
        return -1;
    }

    long long a;
    cout << "Input a: ";
    cin >> a;

    long long a0 = a;
    long long a1 = 18 * a * a + 10;

    if (n <= 1) return a0;
    while (n >= 3) {
        long long cur = 18 * a1 + 10 * a0;
        a0 = a1;
        a1 = cur;
        n -= 1;
    }
    return a1;
}

long long getNumberSequence(int n) {
    if (n < 1) return -1;
    int a;
    cout << "Input a: ";
    cin >> a;

    long long res = getNumberSequenceRecursive(n, a);
    return res;
}

int main()
{
	cout << "\t Kiem tra thuc hanh DSA cuoi ki - 22TNT1" << endl;
	cout << "\t 22120128 - Bui Quoc Huy" << endl;
    int n;
    cout << "Input n: ";
    cin >> n;

    clock_t start, end;
    start = clock();
    cout << "With n = " << n << " : " << getNumberSequence(n) << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Execution time: " << time_taken << endl;
    
    start = clock();
    cout << "With n = " << n << " : " << getNumberSequenceIterative(n) << endl;
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Execution time: " << time_taken << endl;
    cout << "Su dung ham de qui se cham hon do phai tinh lai cac gia tri n nho." << endl;
    return 0;
}

