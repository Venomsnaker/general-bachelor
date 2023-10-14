#include <bits/stdc++.h>
using namespace std;

int SearchIterative(vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i]) return i;
    }
    return -1;
}

int SearchBinary(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] == target) {
            return m;
        }
        else {
            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
    }
    return -1;
}