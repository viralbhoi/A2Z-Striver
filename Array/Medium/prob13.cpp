// Count Subarray sum Equals K
// Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include<bits/stdc++.h>
using namespace std;

// Brute Force: Time O(N^2), Space O(1)
int subarraySumEqualKBrute(vector<int> &nums, int k){
    int n = nums.size();

    int ans = 0;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];

            if(sum == k)
                ans++;
        }
    }

    return ans;
}

// Optimal: Time O(N), Space O(N)
int subarraySumEqualKOptimal(vector<int> &nums, int k){
    int n = nums.size();

    int ans = 0;

    int pre = 0;
    map<int,int> mp;

    mp[0] = 1;

    for(auto num:nums){
        pre += num;
        int rem = pre - k;
        ans += mp[rem];
        mp[pre]++;
    }

    return ans;
}

int main(){
    int n,k;
    cin >> n >>k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout<<subarraySumEqualKBrute(v,k)<<endl;
    cout<<subarraySumEqualKOptimal(v,k)<<endl;


}