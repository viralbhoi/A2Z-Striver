// Search Element in Rotated Sorted Array II
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

#include<bits/stdc++.h>
using namespace std;

// O(n)
bool findInSortedRotatedArrayBrute(vector<int> &nums,int x){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==x)
            return true;
    }
    return false;
}

// O(logn) worst O(n) if all same
bool findInSortedRotatedArrayOptimal(vector<int> &nums,int x){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(nums[mid] == x){
            return true;
        }

        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
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
    return false;
}

int main(){
    vector<int> arr = {3,3,3,1,3,3,3,3,3};
    int target = 1;

    cout << "Brute: " << findInSortedRotatedArrayBrute(arr, target) << endl;
    cout << "Optimal: " << findInSortedRotatedArrayOptimal(arr, target) << endl;

    return 0;
}