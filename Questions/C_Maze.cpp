#include <bits/stdc++.h>
// #define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                  \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a)                 \
    for (int i = 0; i < n; ++i) \
    {                           \
        cout << a[i] << ' ';    \
    }
#define pb push_back
#define ff first
#define ss second
#define viv vector<vector<int>>
#define nah cout << "NO\n";
#define yah cout << "YES\n";
#define be begin()
#define en end()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void bfs(vector<string> &s, int n, int m, int limit)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pair<int, int>> cells;
    queue<pair<int, int>> q;
    bool found = false;
    for (int i = 0; i < n && !found; ++i)
    {
        for (int j = 0; j < m && !found; ++j)
        {
            if (s[i][j] == '.')
            {
                q.push({i, j});
                vis[i][j] = true;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cells.push_back({x, y});

                    int dx[4] = {1, -1, 0, 0};
                    int dy[4] = {0, 0, 1, -1};
                    for (int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                            s[nx][ny] == '.' && !vis[nx][ny])
                        {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                found = true;
            }
        }
    }
    int extra = (int)cells.size() - limit;
    for (int i = 0; i < extra; i++)
    {
        int x = cells.back().first;
        int y = cells.back().second;
        cells.pop_back();
        s[x][y] = 'X';
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << "\n";
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                ct++;
            }
        }
    }
    bfs(s, n, m, ct - k);
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
