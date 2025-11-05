#include <bits/stdc++.h>
using namespace std;
bool isSafe(int n, vector<string> &nQueens, int row, int col)
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
        if (isSafe(n, nQueens, row, col))
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
    if (ans.empty())
    {
        {
            cout << 0 << endl;
        }
    }
    else
    {
        cout << ans.size() << endl;
        for (auto &board : ans)
        {
            for (auto &row : board)
            {
                cout << row << endl;
            }
            cout << endl;
        }
    }
}