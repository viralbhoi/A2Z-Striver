// Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

#include<bits/stdc++.h>
using namespace std;

int findElement (vector<int> &v,int target){
    for(int i=0;i<v.size();i++){
        if(v[i] == target){
            return i;
        }
    }

    return -1;
}

int main(){
    int n;
    cin>>n;


    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    cout<<findElement(v,5)<<endl;
    cout<<findElement(v,115)<<endl;

}