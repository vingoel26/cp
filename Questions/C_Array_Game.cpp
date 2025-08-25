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
    vi a(n);
    vin(a);
    if (k >= 3)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(all(a));
        int ans = a[0], ans1 = 1e18;
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, a[i + 1] - a[i]);
            ans1 = min(ans1, a[i + 1] - a[i]);
        }
        if (k == 1)
        {
            cout << ans << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < i; j++)
                {
                    int v = a[i] - a[j];
                    int p = lower_bound(all(a), v) - a.begin();
                    if (p < n)
                    {
                        ans = min(ans, a[p] - v);
                    }
                    if (p > 0)
                    {
                        ans = min(ans, v - a[p - 1]);
                    }
                }
            cout << ans << endl;
        }
    }
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