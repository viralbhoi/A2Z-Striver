// Rearrange Array Elements by Sign

// Problem Statement:

// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.

#include <bits/stdc++.h>
using namespace std;

// time O(2n) space O(2n)
vector<int> rearrangeBySignBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    vector<int> pos, neg;

    for (auto it : nums)
    {
        if (it < 0)
        {
            neg.push_back(it);
        }
        else
        {
            pos.push_back(it);
        }
    }

    for (int i = 0; i < n; i += 2)
    {
        ans[i] = pos[i / 2];
        ans[i + 1] = neg[i / 2];
    }

    return ans;
}

// time O(n) space O(n)
vector<int> rearrangeBySignOptimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    int posIdx = 0, negIdx = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
        else
        {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
    }

    return ans;
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

    vector<int> ans = rearrangeBySignBrute(v);

    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    ans = rearrangeBySignOptimal(v);

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}