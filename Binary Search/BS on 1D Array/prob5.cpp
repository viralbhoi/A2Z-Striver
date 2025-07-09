// Floor and Ceil in Sorted Array

// Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> nums,int target){
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] <= target){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    if(ans != -1){
        ans = nums[ans];
    }

    return ans;
}

int findCeil(vector<int> nums,int target){
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

    if(ans == nums.size()){
        ans = -1;
    }else{
        ans = nums[ans];
    }

    return ans;
}

int main(){
    vector<int> v = {3, 4, 4, 7, 8, 10};
    int x = 1;

    cout<<findCeil(v,x)<<endl;
    cout<<findFloor(v,x)<<endl;

}