// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
// Negative may appear

#include<bits/stdc++.h>
using namespace std;

// brute O(n^2) just generate all sub array and find max len, space O(1);

int maxLenSubarraySumKBrute(vector<int> &a, long long k){
    int maxLen = 0;
    int n = a.size();

    for(int i=0;i<n;i++){
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];

            if(sum == k){
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    return maxLen;
}

// space O(n) time O(nlogn);
int maxLenSubarraySumKOptimal(vector<int> &a, long long k){
    int maxLen = 0;
    int n = a.size();

    map<long long,int> preSum;
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += a[i];

        if(sum == k){
            maxLen = max(maxLen, i+1);
        }

        long long rem = sum - k;

        if(preSum.find(rem) != preSum.end()){
            maxLen = max(maxLen, i - preSum[rem] + 1);
        }

        if(preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
        }
    }

    return maxLen;
}

int main(){
    int n;
    cin >> n;
    long long k;
    cin>>k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout<< maxLenSubarraySumKBrute(v,k)<<endl;
    cout<< maxLenSubarraySumKOptimal(v,k)<<endl;

}