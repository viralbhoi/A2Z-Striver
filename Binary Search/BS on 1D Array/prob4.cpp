// Search Insert Position
// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

#include<bits/stdc++.h>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}