// select minimum and swap
// complexity =  n + (n-1) + (n-2) + (n-3) + ... + 2 ~= n(n+1)/2 = n^2/2 + n/2 ~= O(n^2)
// check minimum in i to n

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++) // O(n) times
    {
        int mini = i;
        for (int j = i; j < n; j++)  //for 1 iteration O(n-i) ~= O(n) times
        {
            if (a[j] < a[mini])
                mini = j;
        }

        swap(a[i], a[mini]);
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