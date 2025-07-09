// Merge two Sorted Arrays Without Extra Space
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include <bits/stdc++.h>
using namespace std;

// Time complexity O(n+m) space O(n+m)
void mergeSortedArrBrute(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);
    int idx = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[idx] = arr1[i];
            i++;
        }
        else
        {
            arr3[idx] = arr2[j];
            j++;
        }

        idx++;
    }

    while (i < n)
    {
        arr3[idx] = arr1[i];
        i++;
        idx++;
    }

    while (j < m)
    {
        arr3[idx] = arr2[j];
        j++;
        idx++;
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
}

// Time complexity O(min(n,m) + nlogn + mlogm) space O(1)
void mergeSortedArrOptimal(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int left = n - 1, right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

// there is another approach which incluse idea of shel short, but i am not implementing it

void print(vector<int> arr)
{

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    mergeSortedArrBrute(arr1, arr2);
    print(arr1);
    print(arr2);
    mergeSortedArrOptimal(arr1, arr2);

    print(arr1);
    print(arr2);
}