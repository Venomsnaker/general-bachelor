#include <iostream>
#include <algorithm>
using namespace std;

int countUniqueBruteForce(int arr[], int n) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    if (n == 0) return 0;
    int res = 1;

    for (int i = 1; i < n; i++) {
        int j = 0;
        for (; j < i; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (i == j) res++;
    }
    return res;
}

int countUniqueSorting(int arr[], int n) {
    // Time Complexity: O(n*log(n))
    // Space Complexity: O(n)
    if (n == 0) return 0;
    sort(arr, arr + n);
    int i = 1, res = 1;
    
    while (i < n) {
        if (arr[i] != arr[i-1]) res++;
        i++;
    }
    return res;
}

int countUniqueHashmap(int arr[], int n) {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    const int n_const = n;
    int temp[n_const];
    int res = 0;

    for (int i = 0; i < n; i++) {
        temp[arr[i] - '0']++;
    }
    for (int j = 0; j < n; j++) {
        if (temp[j] > 0) res++;
    }
    return res;
}

int main() {
    const int n = 10;
    int arr[] = {1, 2, 3, 3, 7, 4, 1, 9, 11, 3}; 

    cout << countUniqueHashmap(arr, n) << endl;
    return 0;
}