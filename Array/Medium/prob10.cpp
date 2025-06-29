// Set Matrix Zero
// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include<bits/stdc++.h>
using namespace std;

// Brute : time O(n*m*(n+m)) space O(n*m)
vector<vector<int>> setMatrixZeroBrute(vector<vector<int>> mat){
    vector<vector<int>> ansMat = mat;
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                for(int k=0;k<n;k++){
                    ansMat[k][j] = 0;
                }

                for(int k=0;k<m;k++){
                    ansMat[i][k] = 0;
                }
            }
        }
    }

    return ansMat;
}


// Better: time O(n*m) space O(n+m)
vector<vector<int>> setMatrixZeroBetter(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> row(n,0);
    vector<int> col(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(row[i]){
            for(int j=0;j<m;j++){
                mat[i][j] = 0;
            }
        }
    }

    for(int j=0;j<m;j++){
        if(col[j]){
            for(int i=0;i<n;i++){
                mat[i][j] = 0;
            }
        }
    }

    return mat;
}

// Optimal: time O(n*m) space O(1)
vector<vector<int>> setMatrixZeroOptimal(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();

    int col0 = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;

                if(j != 0)
                    mat[0][j] =0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0){
        for(int j=0;j<m;j++)
            mat[0][j] = 0;
    }

    if(col0 == 0){
        for(int i=0;i<n;i++)
            mat[i][0] = 0;
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
    int n, m;
    cin>>n>>m;

    vector<vector<int>> mat(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> ansMat = setMatrixZeroBrute(mat);
    printMatrix(ansMat);
    ansMat = setMatrixZeroBetter(mat);
    printMatrix(ansMat);
    ansMat = setMatrixZeroOptimal(mat);
    printMatrix(ansMat);
}