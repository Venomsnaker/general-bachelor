#include <iostream>
#include <vector>
using namespace std;

int getMaxMod(vector<int> nums) {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int res = 0;

    for (auto val: nums) {
        res += val - 1;
    }
    return res;
}

int main() {
    cout << getMaxMod({1,2,3}) << " ";
    cout << getMaxMod({2,4});
    return 0;
}