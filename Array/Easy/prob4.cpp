// Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

// brute force use set O(nlogn)  space O(n);

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &v)
{
    int i = 0;

    for (int j = 0; j < v.size(); j++)
    {
        if (v[i] != v[j])
        {
            v[i + 1] = v[j];
            i++;
        }
    }

    return i + 1;
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

    int cnt = removeDuplicates(v);

    for (int i = 0; i < cnt; i++)
    {
        cout << v[i] << " ";
    }
}