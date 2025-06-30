// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

#include<bits/stdc++.h>
using namespace std;

// Spcae O(n^2) time O(n^2)
vector<vector<int>> rotate90Brute(vector<vector<int>> &mat){
    vector<vector<int>> ans = mat;
    int n = mat.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = mat[n-j-1][i];
        }
    }

    return ans;
}

// Spcae O(1) (inplace) time O(n^2)
vector<vector<int>> rotate90Optimal(vector<vector<int>> &mat){
    // vector<vector<int>> ans = mat;
    int n = mat.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }

    return mat;
}

void printMatrix(vector<vector<int>> mat){
    for(auto row : mat){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> ansMat = rotate90Brute(mat);
    printMatrix(ansMat);

    ansMat = rotate90Optimal(mat);
    printMatrix(ansMat);
}