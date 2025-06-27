// Kadane's Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.
// also you need not empty subarrays.

#include <bits/stdc++.h>
using namespace std;

// O(n^2) space O(1)
long long maximumSubarraySumBrute(vector<int> &nums)
{
    long long maxi = LONG_LONG_MIN;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// O(n) space O(1)
long long maximumSubarraySumOptimal(vector<int> &nums)
{
    long long maxi = LONG_LONG_MIN;
    long long sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        maxi = max(maxi,sum);

        if(sum<0){
            sum = 0;
        }
    }

    return maxi;
}

vector<int> maximumSubarraySumSubarrayIDX(vector<int> &nums)
{
    long long maxi = LONG_LONG_MIN;
    long long sum = 0;
    int n = nums.size();
    int ansStart = -1, ansEnd = -1;
    int start;

    for (int i = 0; i < n; i++)
    {
        if(sum == 0){
            start = i;
        }
        sum += nums[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        

        if(sum<0){
            sum = 0;
        }
    }

    return {ansStart,ansEnd};

}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maximumSubarraySumBrute(v) << endl;
    cout << maximumSubarraySumOptimal(v) << endl;
    vector<int> ans= maximumSubarraySumSubarrayIDX(v);

    cout<<"MAX SUBARRAY is from [ "<<ans[0] <<" , "<<ans[1]<<" ]"<<endl;

}