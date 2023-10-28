#include <iostream>
#include <cstdlib> 
#include <time.h>
using namespace std;

void print_array(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void sort_bubble(int nums[], int n) {
    if (n == 0) return;
    
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
            if (nums[j] < nums[i]) idx = j;
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
    get_sorts_complexity();
    return 0;
}