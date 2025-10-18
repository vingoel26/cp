#include <bits/stdc++.h>
#define int long long
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
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007
using namespace std;

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    viv vis(n, vi(m, 0));
    string ans = "";
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                stack<pair<int, int>> st;
                st.push({i, j});
                vis[i][j] = 1;
                while (!st.empty())
                {
                    pair<int, int> p = st.top();
                    st.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int r = p.ff + dr[k], c = p.ss + dc[k];
                        if (((r >= 0 and r < n) and (c >= 0 and c < m)) and v[r][c] == '.' and !vis[r][c])
                        {
                            st.push({r, c});
                            vis[r][c] = 1;
                            if(k==0){
                                ans.pb('U');
                            }
                            if(k==1){
                                ans.pb('D');
                            }
                            if(k==2){
                                ans.pb('R');
                            }
                            if(k==3){
                                ans.pb('L');
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}