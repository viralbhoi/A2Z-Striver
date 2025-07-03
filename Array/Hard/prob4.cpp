// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include <bits/stdc++.h>
using namespace std;

// time O(n^4 logn) space O(2*no of unique quads)
vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
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
                for (int l = k + 1; l < n; l++)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
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

// time O(n^3 logn) space O(2* no of unique qauds + n)
vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<vector<int>> ans;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> st1;
            for (int k = j + 1; k < n; k++)
            {
                int pre = nums[i] + nums[j] + nums[k];

                if (st1.find(target - pre) != st1.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], target - pre};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                st1.insert(nums[k]);
            }
        }
    }

    for (auto it : st)
    {
        ans.push_back(it);
    }

    return ans;
}

// time O(n^3) space O(1)
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target)
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

        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int k = j + 1, l = n - 1;

            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        nums[k],
                        nums[l]};

                    ans.push_back(temp);
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }

                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
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