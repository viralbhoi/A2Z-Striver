// Two Sum : Check if a pair with given sum exists in Array
// Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

#include<bits/stdc++.h>
using namespace std;

// O(n^2) time O(1) space
vector<int> twoSumNestedLoops(vector<int> v,int target){
    int n = v.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i] + v[j] == target){
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

// O(nlogn) time O(n) space
vector<int> twoSumWithMap(vector<int> v,int target){
    map<int,int> mp;
    int n = v.size();

    for(int i=0;i<n;i++){
        int rem = target - v[i];

        if(mp.find(rem) != mp.end()){
            return {mp[rem], i};
        }


        mp[v[i]] = i;
    }

    return {-1,-1};
}



int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = twoSumNestedLoops(v,4);

    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = twoSumWithMap(v,8);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}