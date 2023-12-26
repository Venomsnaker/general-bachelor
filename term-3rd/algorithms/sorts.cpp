#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return;
}

void sortBubble(vector<int> &nums)
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int temp, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
    return;
}

void sortSelection(vector<int> &nums)
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int idx, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[idx])
                idx = j;
        }

        if (idx != i)
        {
            swap(nums[idx], nums[i]);
        }
    }
    return;
}

void sortInsertation(vector<int> &nums)
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int key, j, n = nums.size();

    for (int i = 1; i < n; i++)
    {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    return;
}

void sortShell(vector<int> &nums) {
    // Time Complexity: O(nlog(n)^2)
    // Space Complexity: O(1)
    int n = nums.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = nums[i];

            int j;
            for (j = i; j >= gap && nums[j-gap] > temp; j -= gap) {
                nums[j] = nums[j - gap];
            }
            nums[j] = temp;
        }
    }
    return;
}

void merge(vector<int> &nums, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = nums[l + i];
    for (int j = 0; j < n2; j++)
        M[j] = nums[m + 1 + j];

    // reset
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        nums[k] = M[j];
        j++;
        k++;
    }
}

void sortMerge(vector<int> &nums, int l, int r)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(n)
    if (l >= r)
        return;
    int m = l + (r - l) / 2;

    sortMerge(nums, l, m);
    sortMerge(nums, m + 1, r);
    merge(nums, l, m, r);
    return;
}

void heapify(vector<int> &nums, int n, int i)
{
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
        heapify(nums, n, largest);
    }
}

void sortHeap(vector<int> &nums)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(1)
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
    return;
}

int partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

void sortQuick(vector<int> &nums, int l, int r)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(log(n))
    if (l < r)
    {
        int partitionIdx = partition(nums, l, r);
        sortQuick(nums, l, partitionIdx - 1);
        sortQuick(nums, partitionIdx + 1, r);
    }
    return;
}

int getMax(vector<int> nums, int n)
{
    int max = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > max)
            max = nums[i];
    }
    return max;
}

void countSort(vector<int> &nums, int n, int exp)
{
    const int max = 10;
    int output[n];
    int count[max];

    // Initialize count array
    for (int i = 0; i < max; i++)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < n; i++)
        count[(nums[i] / exp) % 10]++;

    // Calculate cumulative count | shift one element upward
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }

    // Match output with the original array
    for (int i = 0; i < n; i++)
        nums[i] = output[i];
}

void sortRadix(vector<int> &nums, int n)
{
    // Time Complexity: O(nk)
    // Space Complexity: O(n + k)
    int max = getMax(nums, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(nums, n, exp);
}

int main()
{
    vector<int> nums = {2, 3, 6, 4, 5, 2, 8, 7, 9, 1};
    printVector(nums);
    // sortHeap(nums);
    // sortMerge(nums, 0, nums.size() - 1);
    sortRadix(nums, nums.size());
    printVector(nums);
    return 0;
}