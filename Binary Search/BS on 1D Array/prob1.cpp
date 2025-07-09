// Binary Search

#include <bits/stdc++.h>
using namespace std;

// time O(n)
int linearSearch(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// time O(logn)
int binarySearch(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// time O(logn)
int binarySearchRec(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarySearchRec(nums, mid + 1, high, target);

    return binarySearchRec(nums, low, mid - 1, target);
}

int searchElement(vector<int> &nums, int target)
{
    return binarySearchRec(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    cout<<linearSearch(a,target)<<endl;
    cout<<binarySearch(a,target)<<endl;
    cout<<searchElement(a,target)<<endl;

}