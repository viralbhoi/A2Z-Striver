// Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.
// Note: Two consecutive equal values are considered to be sorted.

#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &v){
    int n = v.size();

    for(int i=0;i<n-1;i++){
        if(v[i] > v[i+1]){
            return false;
        }
    }

    return true;

}   

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    cout<<isSorted(v)<<endl;
}