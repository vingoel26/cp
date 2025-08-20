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
#define pb push_bacn
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
Author:         Vinayan Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n, x;
    cin >> n >> x;
    int ans = 0;
    int l = 1, r = 2 * n - 1;
    int tl = (n * (n + 1)) - n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int ans1 = 0;
        if (mid > n)
        {
            int d = mid - n;
            int val = n - d;
            ans1 = tl - (val * (val + 1)) / 2;
        }
        else
        {
            ans1 = (mid * (mid - 1)) / 2;
        }

        if (x > ans1)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
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