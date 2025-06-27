// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// dutch national flag algorithm is used in optimal solution;

// 0 to low - 1 contain all 0s
// low to mid - 1 contain all 1s
// mid to high - 1 contain unsorted portion
// high to n contains 2

// if arr[mid] == 0 swap(v[low],v[mid]); mid++; low++; since portion of zero increase
// if arr[mid] == 1 just mid++;
// if arr[mid] == 2 swap(v[high], v[mid]); high--;


#include <bits/stdc++.h>
using namespace std;

// O(nlogn) space O(1)
vector<int> sort012Brute(vector<int> v)
{
    sort(v.begin(), v.end());
    return v;
}

// O(2n) space O(1)
vector<int> sort012Better(vector<int> v)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
            cnt0++;
        else if (v[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        v[i] = 0;

    for (int i = cnt0; i < cnt0 + cnt1; i++)
        v[i] = 1;

    for (int i = cnt0 + cnt1; i < v.size(); i++)
        v[i] = 2;

    return v;
}

// O(n) space O(1)
vector<int> sort012Optimal(vector<int> v)
{
    int mid = 0, low = 0, high = v.size()-1;

    while(mid <= high){
        if(v[mid] == 0){
            swap(v[low],v[mid]);
            mid++;
            low++;
        }else if(v[mid] == 1){
            mid++;
        }else{
            swap(v[mid],v[high]);
            high--;
        }
    }

    return v;

}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = sort012Brute(v);

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

    ans = sort012Better(v);

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

    ans = sort012Optimal(v);

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}