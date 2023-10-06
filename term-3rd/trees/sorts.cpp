#include <bits/stdc++.h>
using namespace std;

void PrintVector(vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void SortBubble(vector<int> &nums) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int temp, n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                Swap(nums[i], nums[j]);
            }
        }
    }
}

void SortSelection(vector<int> &nums) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int idx, n = nums.size();

    for (int i = 0; i < n; i++) {
        idx = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[idx]) idx = j;
        }

        if (idx != i) {
            Swap(nums[idx], nums[i]);
        }
    }
}

void SortInsertation(vector<int> &nums) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int key, j, n = nums.size();

    for (int i = 1; i < n; i++) {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j = j - 1;
        }
        nums[j+1] = key;
    }
}

void Merge(vector<int> &nums, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++) L[i] = nums[l + i];
    for (int j = 0; j < n2; j++) M[j] = nums[m + 1 + j];

    // Reset
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = M[j];
        j++;
        k++;
    }
}

void SortMerge(vector<int> &nums, int l, int r) {
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(n)
    if (l >= r) return;
    int m = l + (r - l) / 2;

    SortMerge(nums, l, m);
    SortMerge(nums, m + 1, r);
    Merge(nums, l, m, r);
}

void SortHeap() {

}

void SortQuick() {

}

void SortRadix() {

}

int main() {
    vector<int> nums = {2, 3, 6, 4, 5, 2, 8, 7, 9, 1};
    PrintVector(nums);
    SortMerge(nums, 0, nums.size() - 1);
    PrintVector(nums);
    return 0;
}