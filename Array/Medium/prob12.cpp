// Spiral Traversal of Matrix
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

#include <bits/stdc++.h>
using namespace std;

// space O(n*m) time O(n*m)
vector<int> spiralOrderTraversal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = m - 1;

    vector<int> ans;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        for (int i = colStart; i <= colEnd; i++)
        {
            ans.push_back(mat[rowStart][i]);
        }
        rowStart++;

        for (int i = rowStart; i <= rowEnd; i++)
        {
            ans.push_back(mat[i][colEnd]);
        }
        colEnd--;

        if (rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                ans.push_back(mat[rowEnd][i]);
            }
            rowEnd--;
        }

        if (colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                ans.push_back(mat[i][colStart]);
            }
            colStart++;
        }
    }

    return ans;
}

void printArray(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = spiralOrderTraversal(mat);
    printArray(ans);
}