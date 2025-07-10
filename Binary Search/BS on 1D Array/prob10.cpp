// Minimum in Rotated Sorted Array
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

int findMinBrute(vector<int> nums)
{
    int ans = *min_element(nums.begin(), nums.end());
    return ans;
}

int findMinOptimal(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;

    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
            }
            break;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }

    return ans;
}