// Implement upper Bound
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low = 0, high = nums.size()-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int x = 10;
    vector<int> nums = {1,2,3,4,5,6,7,8,8,11,12,13};
    cout<<upperBound(nums,x)<<endl;
    nums={10};
    cout<<upperBound(nums,x)<<endl;
    nums = {1};
    cout<<upperBound(nums,x)<<endl;
}