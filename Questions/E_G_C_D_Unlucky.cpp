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
    vi p(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        if (p[i - 1] % p[i] != 0)
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i + 1] % s[i] != 0)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok and p[n - 1] != s[0])
    {
        ok = false;
    }
    if (ok)
    {
        for (int i = 0; i + 1 < n; i++)
        {
            if (__gcd(p[i], s[i + 1]) != p[n - 1])
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
    {
        yah
    }
    else
    {
        nah
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