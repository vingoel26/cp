#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
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
#define en r()
#define all(x) x.begin(), x.r()
#define rall(x) x.rbegin(), x.rr()
#define fast \
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
viv dp(1000005, vector<int>(2,-1));
void solve()
{
    int n;
    cin>>n;
    dp[n][0] = 1;
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][0] = (2*dp[i + 1][0] + dp[i + 1][1]) % mod;
        dp[i][1] = (dp[i + 1][0] + 4*dp[i + 1][1]) % mod;
    }
    cout<<(dp[1][0] + dp[1][1]) % mod<<endl;
}

int32_t main()
{
    fast int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}