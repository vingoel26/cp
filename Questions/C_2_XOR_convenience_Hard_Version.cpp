#include <bits/stdc++.h>
using namespace std;

int MaxNumOfWedges(int **a, int row, int col)
{
    int i, j, k, mx = 0, c;

    int **rs = new int*[row];
    int **cp = new int*[row];
    for(i = 0; i < row; i++) {
        rs[i] = new int[col];
        cp[i] = new int[col];
    }
    
    for(i = 0; i < row; i++)
        for(j = col - 1; j >= 0; j--)
            rs[i][j] = a[i][j] + (j < col - 1 ? rs[i][j + 1] : 0);

    // column prefix sum
    for(j = 0; j < col; j++)
        for(i = 0; i < row; i++)
            cp[i][j] = a[i][j] + (i > 0 ? cp[i - 1][j] : 0);

    // main logic (UNCHANGED)
    for(i = 0; i < row - 1; i++)
        for(j = i + 1; j < row; j++)
            for(k = 0; k < col; k++)
            {
                c = rs[i][k] + rs[j][k] + (j > i + 1 ? cp[j - 1][k] - cp[i][k] : 0);
                if(c > mx) mx = c;
            }
    return mx;
}

int main()
{
    int row, col;
    cin >> row >> col;

    int **a = new int*[row];
    for(int i = 0; i < row; i++)
        a[i] = new int[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> a[i][j];

    cout << MaxNumOfWedges(a, row, col);
    return 0;
}