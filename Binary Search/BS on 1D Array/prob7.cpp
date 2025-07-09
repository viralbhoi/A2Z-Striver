// Count Occurrences in Sorted Array
// Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

#include <bits/stdc++.h>
using namespace std;

int countOccurencesBrute(vector<int> &nums, int target)
{
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            cnt++;
        }
    }

    return cnt;
}

int countOccurencesBetter(vector<int> &nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    if (first == nums.size() || nums[first] != target)
    {
        return 0;
    }

    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    last--;

    return last - first + 1;
}

int countOccurencesOptimal(vector<int> &nums, int target)
{
    int first = -1, last = -1;

    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (first == -1)
    {
        return 0;
    }

    low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last - first + 1;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 6;

    cout << "Brute: " << countOccurencesBrute(nums, target) << "\n";
    cout << "Better: " << countOccurencesBetter(nums, target) << "\n";
    cout << "Best: " << countOccurencesOptimal(nums, target) << "\n";
}