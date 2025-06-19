// statement: Find Second Smallest and Second Largest Element in an array
// assuming always size >= 2

#include<bits/stdc++.h>
using namespace std;

vector<int> secondSmallestandLargest(vector<int> &v){
    int n = v.size();

    //brute force
    
    // sort(v.begin(),v.end());
    // return {v[1],v[n-2]};

    int maxi = INT_MIN, mini = INT_MAX, maxi1 = INT_MIN, mini1 = INT_MAX;

    for(int i=0;i<n;i++){
        if(v[i] >= maxi){
            maxi1=maxi;
            maxi = v[i];
        }else if(v[i] > maxi1 && v[i] < maxi){
            maxi1 = v[i];
        }

        if(v[i] <= mini){
            mini1=mini;
            mini = v[i];
        }else if(v[i] < mini1 && v[i] > mini){
            mini1 = v[i];
        }
    }

    

    return {mini1,maxi1};

}   

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    vector<int> ans = secondSmallestandLargest(v);

    if(ans[0] == INT_MAX || ans[1] == INT_MIN){
        cout<<-1<<endl;
        return 1;
    }

    cout<<ans[0]<<" "<<ans[1]<<endl;
}