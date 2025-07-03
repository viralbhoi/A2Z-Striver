// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

#include<bits/stdc++.h>
using namespace std;

// time O(n^2) space O(1)
int longestSubarrSumZeroBrute(vector<int> &nums){
    int n = nums.size();
    int maxi = 0;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];

            if(sum == 0){
                maxi = max(maxi,j-i+1);
            }
        }
    }

    return maxi;
}

// time O(n) space O(n)
int longestSubarrSumZeroOptimal(vector<int> &nums){
    int n = nums.size();

    int pre = 0;
    unordered_map<int,int> mp;
    int maxi = 0;

    for(int i=0;i<n;i++){
        pre += nums[i];

        if(pre == 0){
            maxi = i+1;
        }else{
            if(mp.find(pre) != mp.end()){
                maxi = max(maxi, i - mp[pre]);
            }else{
                mp[pre] = i;
            }
        }
    }

    return maxi;
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &it : v)
    {
        cin >> it;
    }

    cout<<longestSubarrSumZeroBrute(v)<<endl;
    cout<<longestSubarrSumZeroOptimal(v)<<endl;

}