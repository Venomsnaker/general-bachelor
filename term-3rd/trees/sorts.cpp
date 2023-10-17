#include <bits/stdc++.h>
using namespace std;

void PrintVector(vector<int> nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SortBubble(vector<int> &nums)
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
                Swap(nums[i], nums[j]);
            }
        }
    }
}

void SortSelection(vector<int> &nums)
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
            Swap(nums[idx], nums[i]);
        }
    }
}

void SortInsertation(vector<int> &nums)
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
}

void Merge(vector<int> &nums, int l, int m, int r)
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

void SortMerge(vector<int> &nums, int l, int r)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(n)
    if (l >= r)
        return;
    int m = l + (r - l) / 2;

    SortMerge(nums, l, m);
    SortMerge(nums, m + 1, r);
    Merge(nums, l, m, r);
}

void Heapify(vector<int> nums, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && nums[l] > nums[largest])
        largest = l;

    if (r < n && nums[r] > nums[largest])
        largest = r;

    if (largest != i)
    {
        Swap(nums[i], nums[largest]);
        Heapify(nums, n, largest);
    }
}

void SortHeap(vector<int> nums)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(1)
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(nums, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        Swap(nums[0], nums[i]);
        Heapify(nums, i, 0);
    }
}

int Partition(vector<int> nums, int l, int r)
{
    int idx = 0, pivotEle = nums[r], pivotIdx;
    int *temp = new int[r - l + 1];

    // val < pivot
    for (int i = l; i <= r; i++)
    {
        if (nums[i] < pivotEle)
        {
            temp[idx] = nums[i];
            idx++;
        }
    }

    temp[idx] = pivotEle;
    idx++;

    // val > pivot
    for (int i = l; i <= r; i++)
    {
        if (nums[i] > pivotEle)
        {
            temp[idx] = nums[i];
            idx++;
        }
    }

    // Assign nums with temp
    idx = 0;
    for (int i = l; i <= r; i++)
    {
        if (nums[i] == pivotEle)
        {
            pivotIdx = i;
        }
        nums[i] = temp[idx];
        idx++;
    }
    return pivotIdx;
}

void SortQuick(vector<int> nums, int l, int r)
{
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(n)
    if (l < r)
    {
        int partitionIdx = Partition(nums, l, r);
        SortQuick(nums, l, partitionIdx - 1);
        SortQuick(nums, partitionIdx + 1, r);
    }
    return;
}

int GetMax(vector<int> nums, int n)
{
    int mx = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > mx)
            mx = nums[i];
    }
    return mx;
}

void CountSort(vector<int> nums, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(nums[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] = count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
    {
        nums[i] = output[i];
    }
}

void SortRadix(vector<int> nums, int n)
{
    // Time Complexity: O(kn)
    // Space Complexity: O(d + n)
    int mx = GetMax(nums, n);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        CountSort(nums, n, exp);
}

int main()
{
    vector<int> nums = {2, 3, 6, 4, 5, 2, 8, 7, 9, 1};
    PrintVector(nums);
    SortMerge(nums, 0, nums.size() - 1);
    PrintVector(nums);
    return 0;
}