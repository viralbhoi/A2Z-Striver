// select element and place it on its correct position
// complexity =  n + (n-1) + (n-2) + (n-3) + ... + 2 ~= n(n+1)/2 = n^2/2 + n/2 ~= O(n^2)
// check if left is greater swap
// if already sorted then O(n) in bestcase


#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++) // O(n) times
    {
        int j = i;

        while(j>0 && a[j-1] > a[j]){
            swap(a[j-1], a[j]);
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it : v){
        cin>> it;
    }

    selectionSort(v);

    for(auto it:v){
        cout<<it<<" ";
    }
}