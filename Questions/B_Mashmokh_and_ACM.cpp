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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> fact(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                fact[i].pb(j);
                if (j * j != i)
                {
                    fact[i].pb(i / j);
                }
            }
        }
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            for (int m = 0; m < fact[j].size(); m++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][fact[j][m]]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[k][i]) % mod;
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
