#include <bits/stdc++.h>
using namespace std;

// space O(1) time O(nlogn)
vector<vector<int>> mergeOptimal(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

void print(vector<vector<int>> mat)
{
    for (auto row : mat)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {
        {1, 1000}, {2, 500}, {600, 900}, {1001, 2000}, {1500, 2500}, {3000, 4000}, {3500, 3700}, {3800, 3900}, {5000, 6000}, {7000, 8000}, {8000, 9000}, {8500, 9500}, {10000, 11000}, {10500, 12000}, {15000, 16000}, {15500, 16500}, {17000, 18000}, {17500, 18500}, {19000, 20000}, {19500, 20500}};

    vector<vector<int>> ans;
    ans = mergeOptimal(intervals);
    print(ans);
}