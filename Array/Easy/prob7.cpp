// Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.
// brute maintain temporary array and fist copy non zero then fill remaining space with 0

// optimal ways is to use two pointer i and j where i will point to zero and j will point to first non zero after i, if valid i and j found make swap, in this way we can maintain relative order.

// brute O(n) time complexity O(n) space complexity
// optimal O(n) time complexity O(1) space complexity


#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeroToEndOptimal(vector<int> v){
    int n = v.size();
    int i=0;int j=0;

    // while(i<n){
    //     while(i<n && v[i] != 0){
    //         i++;
    //     }

    //     if(i==n){
    //         break;
    //     }

    //     j = i;

    //     while(j<n && v[j] ==0){
    //         j++;
    //     }

    //     if(j<n){
    //         swap(v[i],v[j]);
    //         i++;
    //     }else{
    //         break;
    //     }
    // }

    for(int i=0;i<n;i++){
        if(v[i] != 0){
            swap(v[i],v[j]);
            j++;
        }
    }

    return v;
}

vector<int> moveZeroToEndBrute(const vector<int> &v){
    int n = v.size();
    vector<int> temp(n,0);

    int idx = 0;

    for(int i=0;i<n;i++){
        if(v[i] != 0){
            temp[idx] = v[i];
            idx++;
        }
    }

    return temp;
}

int main(){
    int n;
    cin>>n;


    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    vector<int> ans = moveZeroToEndBrute(v);

    for(auto it:ans)
        cout<<it<<" ";

    cout<<endl;

    ans = moveZeroToEndOptimal(v);

    for(auto it:ans)
        cout<<it<<" ";

    cout<<endl;
    
}