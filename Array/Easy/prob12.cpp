// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include <bits/stdc++.h>
using namespace std;

// O(n^2) space O(1)
int appearsOnceBrute(vector<int> &v)
{
    int ans = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if (v[i] == v[j] && j != i)
            {
                check = false;
                break;
            }
        }

        if (check)
            ans = v[i];
    }

    return ans;
}

// O(nlogn) space O(1)
int appearsOnceBettersSpace(vector<int> v)
{
    sort(v.begin(), v.end());

    int n = v.size();

    for (int i = 0; i < n - 1; i += 2)
    {
        if (v[i] != v[i + 1])
        {
            return v[i];
        }
    }

    return v.back();
}

// O(nlogn) (if unordered_map O(n)) space O(n)
int appearsOnceBettersTime(vector<int> v)
{
    map<int, int> mp;

    for (auto it : v)
        mp[it]++;

    int ans = 0;

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            ans = it.first;
            break;
        }
    }

    return ans;
}

// O(n) space O(1)
int appearsOnceOptimal(vector<int> v)
{
    int xr = 0;

    for (auto it : v)
    {
        xr ^= it;
    }

    return xr;
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

    cout << appearsOnceBrute(v) << endl;
    cout << appearsOnceBettersSpace(v) << endl;
    cout << appearsOnceBettersTime(v) << endl;
    cout << appearsOnceOptimal(v) << endl;
}