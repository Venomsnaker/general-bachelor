#include <iostream>
#include <string>
using namespace std;

void sortString() {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    string s = "sortingdata";

    for (int i = 0; i < s.size(); i++) {
        int cur = i;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] < s[cur]) cur = j;
        }
        if (cur != i) swap(s[i], s[cur]);
    }
    cout << s << endl;
}

void sortToBack() {
    const int n = 7;
    int arr[n] = {9, 2, 6, 7, 10, 8, 5};

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (arr[j] % 2 == 0) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    sortToBack();
    return 0;
}