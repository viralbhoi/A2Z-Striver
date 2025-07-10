// Search Element in a Rotated Sorted Array
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

#include<bits/stdc++.h>
using namespace std;

// O(n)
int findInSortedRotatedArrayBrute(vector<int> &nums,int x){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==x)
            return i;
    }
    return -1;
}

// O(logn)
int findInSortedRotatedArrayOptimal(vector<int> &nums,int x){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(nums[mid] == x){
            return mid;
        }

        if(nums[low] <= nums[mid]){
            if(nums[low] <= x && x <= nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(nums[mid] <= x && x <= nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 1000;

    cout << "Brute: " << findInSortedRotatedArrayBrute(arr, target) << endl;
    cout << "Optimal: " << findInSortedRotatedArrayOptimal(arr, target) << endl;

    return 0;
}