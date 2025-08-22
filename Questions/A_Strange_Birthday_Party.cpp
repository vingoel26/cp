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
    vi a(n), b(m);
    vin(a);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    vi p1(n), p2(m);
    p1[0] = b[a[0] - 1];
    for (int i = 1; i < n; i++)
    {
        p1[i] = p1[i - 1] + b[a[i] - 1];
    }
    p2[0] = b[0];
    for (int i = 1; i < m; i++)
    {
        p2[i] = p2[i - 1] + b[i];
    }
    int s1 = 0, s2 = 0;
    int ans = 1e17;
    for (int i = 0; i < min(n, m); i++)
    {
        if (n - i - 2 < 0)
        {
            ans = min(ans, p2[i]);
            continue;
        }
        int ans1 = p1[n - i - 2] + p2[i];
        ans = min(ans, ans1);
    }
    ans = min(ans, p1[n - 1]);
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