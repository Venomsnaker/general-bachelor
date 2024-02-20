#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int getSmallestK(int l, int r) {
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    return ceil((r - l + 1) / 2) + 1;
}

int main() {
    for (int i = 2; i <= 5; i++) {
        cout << getSmallestK(0, i) << endl;
    }
    return 0;
}