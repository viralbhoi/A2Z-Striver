// Push maximum to last by adjecent swaping
// complexity =  n + (n-1) + (n-2) + (n-3) + ... + 2 ~= n(n+1)/2 = n^2/2 + n/2 ~= O(n^2)
// go from 0 to n-1-i
// if no swap found break for better complexity so, best case is O(n)

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n ; i++) // O(n) times
    {
        bool performSwap = false;
        for (int j = 0; j < n-i-1 ; j++)  //for 1 iteration O(n-i) ~= O(n) times
        {
            if (a[j+1] < a[j]){
                swap(a[j],a[j+1]);
                performSwap = true;
            }
        }

        if(!performSwap){
            break;
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

    bubbleSort(v);

    for(auto it:v){
        cout<<it<<" ";
    }
}