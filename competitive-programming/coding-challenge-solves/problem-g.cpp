#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num == 2) return true;
    if (num <= 1 || num % 2 == 0) return false;

    for (int i = 3; i < ceil(num/2); i+=2) {
        if (num % i == 0) return false;
    }
    return true;
}

long sumOfCubedDigits(int num) {
    long sum = 0;
    int digit;

    while (num > 0) {
        digit = num % 10;
        sum += pow(digit, 3);
        num /= 10;
    }
    return sum;
}

long findKNumber(int k) {
    int count = 0, i = 1;
    long current = INT_MIN;

    while (count < k) {
        current = sumOfCubedDigits(i);
        if (isPrime(current)) {
            count += 1;
            if (count == k) return i;
        }
        i++;
    }
    return 0;
}

int main() {
    for (int i = 1; i < 6; i++) {
        cout << findKNumber(i) << " ";
    }
    return 0;
}