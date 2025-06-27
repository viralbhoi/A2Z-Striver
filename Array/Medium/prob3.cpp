// Find the Majority Element that occurs more than N/2 times

// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

//  moore's voting algorithm for optimal solution -> non majority cancels the majority, but since majority is > n/2 at last atleast one elem of majority exist 

#include <bits/stdc++.h>
using namespace std;

// Brute : time O(n^2) space O(1)
int majorityElementBrute(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
            }
        }

        if (cnt > (n / 2))
        {
            return nums[i];
        }
    }

    return -1; // has to return something
}

// better : Time O(nlogn) space O(n)
int majorityElementBetter(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    for (auto num : nums)
    {
        mp[num]++;
    }

    for (auto it : mp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1; // has to return something
}

// time O(2n) space O(1)
int majorityElementOptimal(vector<int> &nums)
{
    int n = nums.size();

    int cnt = 0;
    int ele;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            ele = nums[i];
            cnt++;
        }
        else if (nums[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele)
        {
            cnt1++;
        }
    }

    if (cnt1 > (n / 2))
    {
        return ele;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Majority Element (Brute): " << majorityElementBrute(v) << endl;
    cout << "Majority Element (Better): " << majorityElementBetter(v) << endl;
    cout << "Majority Element (Optimal): " << majorityElementOptimal(v) << endl;
}