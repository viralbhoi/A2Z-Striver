// Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

// brute :- take temporary vector and do operation (O(n) Space and O(n) time)

// optimal : do inplace rotation using reversal logic
// for right reverse first n - k element then n-k+1 to last element and then reverse whole array
// for left reverse first  k element then k+1 to last element and then reverse whole array
// both have O(1) space complexity ans O(n) time comlexity;

// e.g. n = 6 , k = 2 
// 1 2 3 4 5 6

// right :
// step 1 : 4 3 2 1 5 6 (first n-k = 4 elements);
// step 2 : 4 3 2 1 6 5 (n-k+1 to last element);
// step 3 : 5 6 1 2 3 4 (reverse whole array);

// left :
// step 1 : 2 1 3 4 5 6 (first k = 2 elements);
// step 2 : 2 1 6 5 4 3 (k+1 to last element);
// step 3 : 3 4 5 6 1 2 (reverse whole array);




#include <bits/stdc++.h>
using namespace std;

vector<int> rotateRightBrute(vector<int> &v, int k)
{
    int n = v.size();
    k = k % n; // in case k > n
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = v[i];
    }

    return temp;
}

vector<int> rotateLeftBrute(vector<int> &v, int k)
{
    int n = v.size();
    k = k % n; // in case k > n
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[i] = v[(i + k) % n];
    }

    return temp;
}

vector<int> rotateRightOptimal(vector<int> v, int k)
{
    int n = v.size();
    k = k % n; // in case k > n

    reverse(v.begin(), v.begin() + n - k);
    reverse(v.begin() + n - k, v.end());
    reverse(v.begin(), v.end());

    return v;
}

vector<int> rotateLeftOptimal(vector<int> v, int k)
{
    int n = v.size();
    k = k % n; // in case k > n

    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (auto &it : v)
    {
        cin >> it;
    }

    vector<int> ans = rotateRightBrute(v, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    ans = rotateLeftBrute(v, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    ans = rotateRightOptimal(v, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    ans = rotateLeftOptimal(v, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
