// First and Last occurrence in a sorted array
// Given a sorted array of N integers, write a program to find the index of the first and last occurrence of the target key. If the target is not found then return -1.

#include <bits/stdc++.h>
using namespace std;

vector<int> findFirstAndLastOccurencesBrute(vector<int> &nums, int target)
{
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }

    return {first, last};
}

vector<int> findFirstAndLastOccurencesBetter(vector<int> &nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    if (first == nums.size() || nums[first] != target)
    {
        return {-1, -1};
    }

    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    last--;

    return {first, last};
}

vector<int> findFirstAndLastOccurencesBest(vector<int> &nums, int target)
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
        return {-1, -1};
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

    return {first, last};
}

int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    vector<int> res1 = findFirstAndLastOccurencesBrute(nums, target);
    vector<int> res2 = findFirstAndLastOccurencesBetter(nums, target);
    vector<int> res3 = findFirstAndLastOccurencesBest(nums, target);

    cout << "Brute: " << res1[0] << " " << res1[1] << "\n";
    cout << "Better: " << res2[0] << " " << res2[1] << "\n";
    cout << "Best: " << res3[0] << " " << res3[1] << "\n";

}