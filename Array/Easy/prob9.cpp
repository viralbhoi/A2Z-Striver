// Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

// The union of two arrays can be defined as the common and distinct elements in the two arrays.
// NOTE: Elements in the union should be in ascending order.

// with set space O(n+m) time O((n+m)log(n+m))
// without set space O(n+m) time O(n+m)

#include<bits/stdc++.h>
using namespace std;

vector<int> unionWithSet(vector<int> &a, vector<int> &b){
    set<int> st;

    for(auto it: a){
        st.insert(it);
    }

    
    for(auto it: b){
        st.insert(it);
    }

    vector<int> ans;

    for(auto it:st){
        ans.push_back(it);
    }

    return ans;
}

vector<int> unionWithoutSet(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    int i=0, j=0;

    vector<int> ans;

    while(i<n && j<m){
        while(i+1<n && a[i] == a[i+1]){
            i++;
        }

        while(j+1<m && b[j] == b[j+1]){
            j++;
        }

        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }else if(a[i] > b[j]){
            ans.push_back(b[j]);
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    while(i<n){
        while(i+1<n && a[i] == a[i+1]){
            i++;
        }
        ans.push_back(a[i]);
        i++;
    }

    while(j<m){
        while(j+1<m && b[j] == b[j+1]){
            j++;
        }
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n),b(m);

    for(auto &it:a){
        cin>>it;
    }
    for(auto &it:b){
        cin>>it;
    }

    vector<int> ans = unionWithSet(a,b);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

    ans = unionWithoutSet(a,b);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}