#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> temp;
    for (int i = 0; i < n; i++) temp[arr[i]]++;
    return temp.size();
}

int getMaxDiff(vector<int> arr) {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    if (arr.size() < 2) return -1;
    int top = arr[0];
    int bottom = arr[0];
    int maxProfit = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > top) {
            top = arr[i];
            maxProfit = max(top - bottom, maxProfit);
        } else if (arr[i] < bottom) {
            bottom = arr[i];
            top = arr[i];
        }
    }
    return maxProfit;
}
 
int main() {
    vector<int> arr = {1, 2, 3, 4, 10};
    cout << getMaxDiff(arr) << endl;
    return 0;
}