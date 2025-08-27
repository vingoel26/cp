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
    int ans = 0;
    for (int i = 1; i < n; i = i + 2)
    {
        int p = 0;
        if (i != 0)
        {
            p += a[i - 1];
        }
        if (i != n - 1)
        {
            p += a[i + 1];
        }
        ans += max(0LL, p - a[i]);
        if (i != n - 1 and p>a[i])
        {
            a[i + 1] = max(0LL,a[i+1]-(p-a[i]));
        }
    }
    // vout(a);
    // cout<<endl;
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