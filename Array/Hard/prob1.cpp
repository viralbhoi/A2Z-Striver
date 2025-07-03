// Program to generate Pascal's Triangle
// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

#include<bits/stdc++.h>
using namespace std;

// Variation 1

long long factorial(int x){
    long long f = 1;

    for(int i=2;i<=x;i++){
        f *= i;
    }

    return f;
}

//Brute
long long findPascalElementBrute(int r, int c){
    return (factorial(r-1)/(factorial(c-1) * factorial(r-c)));
}

long long nCr(int n, int r){
    long long ans = 1;

    for(int i=0;i<r;i++){
        ans *= (n - i);
        ans /= (i+1);
    }

    return ans;
}
// Optimal
long long findPascalElementOptimal(int r, int c){
    return nCr(r-1,c-1);
}

// Variation 2:

// Brute
vector<long long> pascalTriangleRowBrute(int n){
    vector<long long> ans;

    for(int i=1;i<=n;i++){
        ans.push_back(nCr(n-1,i-1));
    }

    return ans;
} 

// optimal
vector<long long> pascalTriangleRowOptimal(int n){
    vector<long long> ans;
    ans.push_back(1);
    long long curr = 1;

    for(int i=1;i<n;i++){
        curr *= (n-i);
        curr /= (i);

        ans.push_back(curr);
    }

    return ans;
} 

// Variation 3:

vector<vector<long long>> pascalTriangleBrute(int n){
    vector<vector<long long>> ans;

    for(int row = 1;row <= n; row++){
        vector<long long> temp;
        for(int col = 1; col <= row; col++){
            temp.push_back(nCr(row-1,col-1));
        }
        ans.push_back(temp);
    }

    return ans;
}

vector<vector<long long>> pascalTriangleOptimal1(int n){
    vector<vector<long long>> ans;

    for(int row=1;row<=n;row++){
        ans.push_back(pascalTriangleRowOptimal(row));
    }

    return ans;
}

vector<vector<long long>> pascalTriangleOptimal2(int n){
    vector<vector<long long>> ans;

    vector<long long> prev = {1};

    ans.push_back(prev);

    for(int i=1;i<n;i++){
        vector<long long> temp(prev.size() + 1);
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)
                temp[j] = 1;
            else
                temp[j] = prev[j] + prev[j-1];
        }

        ans.push_back(temp);
        prev = temp;
    }

    return ans;
}