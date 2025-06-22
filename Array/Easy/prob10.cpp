// Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

#include<bits/stdc++.h>
using namespace std;

//O(n^2) space O(1)

int missingNumBrute(vector<int> &a){
    int n = a.size() + 1;

    for(int i=1;i<=n;i++){
        bool check = false;
        for(int j=0;j<n-1;j++){
            if(a[j] == i){
                check = true;
                break;
            }

        }
        if(!check){
            return i;
        }
    }

    return -1; // i have to return something so writtent this
}

//O(nlogn) O(n) if used unordered_map space O(n)
int missingNumBetterTime(vector<int> &a){
    int n = a.size() + 1;

    map <int,int> mp;

    for(auto it:a){
        mp[it]++;
    }

    for(int i=1;i<=n;i++){
        if(mp[i] == 0){
            return i;
        }
    }

    return -1; // i have to return something so writtent this
}

// O(nlogn) space O(1);

int missingNumBetterSpace(vector<int> a){
    sort(a.begin(),a.end());

    if(a[0] != 1){
        return 1;
    }

    for(int i=0;i<a.size()-1;i++){
        if(a[i] != a[i+1] - 1){
            return a[i]+1;
        }
    }

    return a.size()+1;
}

// O(n) space O(1)
int missingNumViaSum(vector<int> &a){
    long long sum = 0;

    for(auto it : a){
        sum += it;
    }

    long long sum_till_N= 1LL*(a.size()+1)*(a.size()+2)/2;

    return static_cast<int>(sum_till_N - sum);
}

// O(n) space O(1)

int missingNumViaXor(vector<int> &a){
    int xor1 = 0, xor2 = 0;

    for(int i=0;i<a.size();i++){
        xor1 ^= a[i];
        xor2 ^=(i+1);
    }

    xor2 ^= (a.size()+1);

    return xor1 ^ xor2;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n-1);

    for(auto &it:v){
        cin>>it;
    }

    cout<<missingNumBrute(v)<<endl;
    cout<<missingNumBetterSpace(v)<<endl;
    cout<<missingNumBetterTime(v)<<endl;
    cout<<missingNumViaSum(v)<<endl;
    cout<<missingNumViaXor(v)<<endl;

}