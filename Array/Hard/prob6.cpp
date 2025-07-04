// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k

#include <bits/stdc++.h>
using namespace std;

// Time: O(n^2) Space: O(1)
long long countXorSumKBrute(vector<int> &nums, int k)
{
    long long ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr = xr ^ nums[j];

            if (xr == k)
            {
                ans++;
            }
        }
    }

    return ans;
}

// Time: O(n) Space: O(n)
long long countXorSumKOptimal(vector<int> &nums, int k)
{
    long long ans = 0;
    int n = nums.size();
    int xr = 0;

    unordered_map<int, int> mp;
    mp[0]++;
    for (int i = 0; i < n; i++)
    {
        xr ^= nums[i];
        ans += mp[xr ^ k];
        mp[xr]++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &it : v)
    {
        cin >> it;
    }

    cout<<countXorSumKBrute(v,6)<<endl;
    cout<<countXorSumKOptimal(v,6)<<endl;

}