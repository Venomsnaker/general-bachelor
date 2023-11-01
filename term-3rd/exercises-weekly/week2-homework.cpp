#include <iostream>
#include <chrono>
using namespace std;

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

int search_binary(int nums[], int l, int r, int target) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] == target) return m + 1;
        else {
            if (target > nums[m]) l = m + 1;
            else r = m - 1; 
        }
    }
    return l;
}

void sort_binary_insertation_sort(int nums[], int n) {
    int j, key, loc = 0;
    
    for (int i = 1; i < n; i++) {
        j = i - 1;
        key = nums[i];
        loc = search_binary(nums, 0, j, key);

        while (j >= loc)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void get_merge_result(int nums[], int l, int m, int r) {
    const int n1 = m - l + 1;
    const int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    
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

    while (i < n1) {
        nums[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        nums[k] = R[j];
        j++; k++;
    }
    delete[] L;
    delete[] R;
}

void sort_merge(int nums[], int n, int l, int r) {
    if (l >= r) return;
    int m = l + (r-l) / 2;

    sort_merge(nums, n, l, m);
    sort_merge(nums, n, m + 1, r);
    get_merge_result(nums, l, m, r);
}


int get_partition_idx(int nums[], int n, int l, int r) {
    int paritionIdx = nums[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (nums[j] <= paritionIdx) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[r]);
    return i + 1;
}

void sort_quick(int nums[], int n, int l, int r) {
    if (l < r) {
        int paritionIdx = get_partition_idx(nums, n, l ,r);
        sort_quick(nums, n, l, paritionIdx - 1);
        sort_quick(nums, n, paritionIdx + 1, r);
    }
    return;
}

void sort_heap_heapify(int nums[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && nums[l] > nums[largest])
        largest = l;
    if (r < n && nums[r] > nums[largest])
        largest = r;

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        sort_heap_heapify(nums, n, largest);
    }
}

void sort_heap(int nums[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        sort_heap_heapify(nums, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        sort_heap_heapify(nums, i, 0);
    }
}

// Helper Functions
void print_array(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void test_sort() {
    const int n = 21;
    int nums[n];

    for (int i = 0; i < n; i++) {
        nums[i] = rand() % 100;
    }
    print_array(nums, n);
    sort_binary_insertation_sort(nums, n);
    print_array(nums, n);
}

void display_complexity() {
    const int n = 1000;
    int nums[n];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < n; j++) {
            nums[j] = rand() % 100;
        }
        //print_array(nums, n);
        auto start = chrono::steady_clock::now();
        sort_bubble(nums, n);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
    }
}

int main() {
    display_complexity();
    return 0;
}