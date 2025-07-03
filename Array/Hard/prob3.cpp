// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include <bits/stdc++.h>
using namespace std;

// time O(n^3 logn) space O(n)
vector<vector<int>> tripletSumZeroBrute(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }
            }
        }
    }

    for (auto it : st)
    {
        ans.push_back(it);
    }

    return ans;
}

// time O(n^2 logn) space O(n)
vector<vector<int>> tripletSumZeroBetter(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> st1;
        for (int j = i + 1; j < n; j++)
        {
            int pre = nums[i] + nums[j];

            if (st1.find(-pre) != st1.end())
            {
                vector<int> temp = {nums[i], nums[j], -pre};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            st1.insert(nums[j]);
        }
    }

    for (auto it : st)
    {
        ans.push_back(it);
    }

    return ans;
}

// time O(n^2) space O(1)
vector<vector<int>> tripletSumZeroOptimal(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};

                ans.push_back(temp);

                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }

                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
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
}