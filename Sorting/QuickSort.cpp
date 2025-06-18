// pickup up a pivot and place it to its correct position
// we can choose any element as a pivot
// smaller in left larger on right.
// bestcase = O(nlogn)
// avg case = O(nlogn)
// worst case = O(n^2)
// space = O(1)

#include <bits/stdc++.h>
using namespace std;

int getPartition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low, j = high;

    while (i < j)
    {
        while(i<=high && v[i] <= pivot){
            i++;
        }

        while(j>=low && v[j] > pivot){
            j--;
        }

        if(i<j){
            swap(v[i],v[j]);
        }
    }

    swap(v[low],v[j]);

    return j;
}

void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivot = getPartition(v, low, high);
        quickSort(v, low, pivot - 1);
        quickSort(v, pivot + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &it : v)
    {
        cin >> it;
    }

    quickSort(v,0,n-1);

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}
