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
vi pal;
bool palind(int n)
{
    int n1 = n;
    int n2 = 0;
    while (n1 > 0)
    {
        n2 = n2 * 10 + n1 % 10;
        n1 /= 10;
    }
    if (n2 == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// void solve()
// {
//     int n;
//     cin >> n;
    
//     cout << dp[n][pal.size()] << endl;
// }

int32_t main()
{
    fast int t = 1;
    cin >> t;
    for (int i = 0; i < 4 * 1e4 + 1; i++)
    {
        if (palind(i))
        {
            pal.pb(i);
        }
    }
    int n=4*1e4;
    viv dp(n + 1, vi(pal.size() + 1));
    for (int j = 1; j < 1 + pal.size(); j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j < pal.size() + 1; j++)
        {
            if (pal[j - 1] <= i)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - pal[j - 1]][j]) % mod;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    while (t--)
    {
        int n1;
        cin>>n1;
        cout<<dp[n1][pal.size()]<<endl;
    }
    return 0;
}