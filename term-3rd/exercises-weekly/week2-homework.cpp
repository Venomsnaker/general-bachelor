#include <iostream>
#include <cstdlib> 
#include <time.h>
using namespace std;

// Helper Functions
void print_array(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void test_sort() {
    const int n = 20;
    int nums[n];

    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
    }
    print_array(nums, n);
    sort_selection(nums, n);
    print_array(nums, n);
}

// Sort Algorithms
void sort_bubble(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[i]) swap(nums[i], nums[j]);
        }
    }
}

void sort_selection(int nums[], int n) {
    int idx;

    for (int i = 0; i < n; i++) {
        idx = i;

        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[idx]) idx = j;
        }
        if (idx != i) swap(nums[idx], nums[i]);
    }
}

void sort_insertation(int nums[], int n) {
    int key = 0, j;

    for (int i = 1; i < n; i++) {
        key = nums[i];
        j = i - 1;

        while(j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void sort_merge_helper(int nums[], int l, int m, int r) {
    const int n1 = abs(m - l + 1);
    const int n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = nums[i + l];
    for (int j = 0; j < n2; j++) R[j] = nums[j + m + 1];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < 0) {
        nums[k] = L[i];
        i++; k++;
    }

    while (j < 0) {
        nums[k] = R[j];
        j++; k++;
    }

}

void sort_merge(int nums[], int n, int l, int r) {
    if (l >= r) return;
    int m = l + (r-l) / 2;

    sort_merge(nums, n, l, m);
    sort_merge(nums, n, m + 1, r);
    sort_merge_helper(nums, l, m, r);
}

// Display Functions
void get_sorts_complexity() {
    clock_t start;
    double time_taken;
    const int n = 10000;
    int nums[n];
    cout << "So sanh cac loai sort voi " << n << " mau." << endl;

    cout << "Selection Sort" << endl;
    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
    }
    start = clock();
    sort_selection(nums, n);
    time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien Selection Sort la: " << time_taken << endl << endl;

    cout << "Bubble Sort" << endl;
    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
    }
    start = clock();
    sort_bubble(nums, n);
    time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien Bubble Sort la: " << time_taken << endl << endl;

    cout << "Insertation Sort" << endl;
    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
    }
    start = clock();
    sort_insertation(nums, n);
    time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien Insertation Sort la: " << time_taken << endl << endl;
    return;
}

int main() {
    test_sort();
    return 0;
}