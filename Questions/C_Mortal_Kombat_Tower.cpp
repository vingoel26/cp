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
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    viv dp(n + 1, vi(2,1e9));
    dp[0][1] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 1; k <= min(n - i, 2LL); k++)
            {
                int s;
                if(k==1){
                    s=a[i];
                }
                else{
                    s=a[i]+a[i+1];
                }
                if(j==0){
                    dp[i+k][1]=min(dp[i+k][1],dp[i][0]);
                }
                else{
                    dp[i+k][0]=min(dp[i+k][0],dp[i][1]+s);
                }
            }

    cout << min(dp[n][0], dp[n][1]) << endl;
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