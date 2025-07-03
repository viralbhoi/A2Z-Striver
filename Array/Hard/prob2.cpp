// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

#include <bits/stdc++.h>
using namespace std;

// O(n^2) time O(1) space
vector<int> majorityElementsBrute(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        if (ans.size() == 0 || ans[0] != nums[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }

            if (cnt > n / 3)
            {
                ans.push_back(nums[i]);
            }
        }

        if(ans.size() == 2){
            break;
        }
    }

    return ans;
}

// O(nlogn) time O(n) space
vector<int> majorityElementsBetter(vector<int> &nums)
{
    vector<int> ans;
    map<int, int> mp;
    int n = nums.size();

    for (auto num : nums)
    {
        mp[num]++;
    }

    for (auto &it : mp)
    {
        if (it.second > n / 3)
        {
            ans.push_back(it.first);
        }
    }

    return ans;
}

// O(n) time O(1) space
vector<int> majorityElementsOptimal(vector<int> &nums)
{
    int ele1, ele2, cnt1 = 0, cnt2 = 0;
    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0)
        {
            ele1 = nums[i];
        }
        else if (cnt2 == 0)
        {
            ele2 = nums[i];
        }

        if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (auto it : nums)
    {
        if (it == ele1)
            cnt1++;
        else if (it == ele2)
            cnt2++;
    }

    if (cnt1 > n / 3)
        ans.push_back(ele1);
    if (cnt2 > n / 3)
        ans.push_back(ele2);

    return ans;
}

void printArray(vector<int> v)
{
    if (v.size() == 0)
    {
        cout << "{}";
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
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

    vector<int> ans = majorityElementsBrute(v);
    printArray(ans);
    ans = majorityElementsBetter(v);
    printArray(ans);
    ans = majorityElementsOptimal(v);
    printArray(ans);
}