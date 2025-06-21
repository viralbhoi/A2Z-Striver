// Problem Statement: Given an array of N integers, left rotate the array by one place.
// brute force can be thinked as take temporary vector and store value in it.
// which is O(n) time complexity and O(n) space complexity

#include<bits/stdc++.h>
using namespace std;

vector<int> rotateLeftByOneOptimal(vector<int> & v){ // still O(n) but space complexity is reduced to O(1)
    int n = v.size();

    int temp = v[0];

    for(int i=1;i<n;i++){
        v[i-1] = v[i];
    }

    v[n-1] = temp;

    return v;
}

vector<int> rotateLeftByOneBrute(vector<int> & v){
    int n = v.size();

    vector<int> temp(n);

    for(int i=1;i<n;i++){
        temp[i-1] = v[i];
    }

    temp[n-1] = v[0];

    return temp;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    vector<int> ans = rotateLeftByOneBrute(v);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans = rotateLeftByOneOptimal(v);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

}