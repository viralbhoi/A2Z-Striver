// Find out how many times the array has been rotated
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

#include <bits/stdc++.h>
using namespace std;

int findMinRotationBrute(vector<int> nums)
{
    int ans = min_element(nums.begin(), nums.end()) - nums.begin();
    return ans;
}

int findMinRotationOptimal(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;

    int ans = INT_MAX;
    int idx = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                idx = low;
            }
            break;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                idx = low;
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }

    return idx;
}