// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

// time O(n) space O(1)

#include<bits/stdc++.h>
using namespace std;

int maxConsicutiveOnes(const vector<int> &a){
    int curr_cnt = 0;
    int max_cnt = 0;
    
    for(int i=0;i<a.size();i++){
        if(a[i] != 1){
            max_cnt =max(max_cnt, curr_cnt);
            curr_cnt = 0;
        }else{
            curr_cnt++;
        }
    }

    if(curr_cnt){
        max_cnt = max (max_cnt, curr_cnt);
    }

    return max_cnt;
}

int main(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxConsicutiveOnes(v)<<endl;
}