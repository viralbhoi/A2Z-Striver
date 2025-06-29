// Leaders in an Array

// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> leadersInArrayBrute(vector<int> &v)
{
    vector<int> ans;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] > v[i])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
        {
            ans.push_back(v[i]);
        }
    }

    return ans;
}

vector<int> leadersInArrayOptimal(vector<int> &v)
{
    vector<int> ans;
    int n = v.size();

    int currMax = v[n - 1];

    ans.push_back(currMax);

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > currMax)
        {
            currMax = v[i];
            ans.push_back(currMax);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void printArray(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
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

    vector<int> ans = leadersInArrayBrute(v);
    printArray(ans);

    ans = leadersInArrayOptimal(v);
    printArray(ans);
}