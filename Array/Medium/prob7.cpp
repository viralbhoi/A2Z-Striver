// next_permutation : find next lexicographically greater permutation

// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

#include <bits/stdc++.h>
using namespace std;

// brute force wil be to generate all permutation and then find the next permutation which is lexographically smallest but greater than current

// on this case O(n! * n) time and same for space

// Better has O(n) time complexity
vector<int> nextPermutationBetter(vector<int> v)
{
    next_permutation(v.begin(), v.end());
    return v;
}

// Optimal has O(n) time complexity which is implementation of next_permutation function.
vector<int> nextPermutationOptimal(vector<int> v)
{

    int dipIdx = -1;

    int n = v.size();

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            dipIdx = i;
            break;
        }
    }

    if (dipIdx == -1)
    {
        reverse(v.begin(), v.end());
        return v;
    }

    for (int i = n - 1; i > dipIdx; i--)
    {
        if (v[i] > v[dipIdx])
        {
            swap(v[i], v[dipIdx]);
            break;
        }
    }

    reverse(v.begin() + dipIdx + 1, v.end());

    return v;
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

    vector<int> ans;

    // for (auto it : ans)
    //     cout << it << " ";
    // cout << endl;

    ans = nextPermutationBetter(v);

    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    ans = nextPermutationOptimal(v);

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}