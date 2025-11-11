#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, vector<string> &nQueens, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (nQueens[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (nQueens[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (nQueens[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void board(int n, vector<vector<string>> &ans, vector<string> &nQueens, int row)
{
    if (row == n)
    {
        ans.push_back(nQueens);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isPossible(n, nQueens, row, col))
        {
            nQueens[row][col] = 'Q';
            board(n, ans, nQueens, row + 1);
            nQueens[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> nQueens(n, string(n, '.'));
    board(n, ans, nQueens, 0);
    int n1=ans.size();
    cout << n1 << endl;
    for (int i=0;i<n1;i++)
    {
        for (int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
}