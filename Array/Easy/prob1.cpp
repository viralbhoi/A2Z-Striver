//Statement: Given an array, we have to find the largest element in the array.

#include<bits/stdc++.h>
using namespace std;

int maxElementRecursive(vector<int> &v, int i, int maxi){
    if(i == v.size()){
        return maxi;
    }

    return maxElementRecursive(v,i+1, max(v[i],maxi));
}

int findMaxElement(vector<int> &v){
    int n = v.size();

    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        maxi = max(v[i], maxi);
    }

    return maxi;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    cout<<findMaxElement(v)<<endl;
    cout<<maxElementRecursive(v,0,INT_MIN)<<endl;



}