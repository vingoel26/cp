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
vi p(40);
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int m = n;
    int x = 0;
    int d1 = 0;
    vi d2;
    while (m > 0)
    {
        int d = m % 3;
        d1 += d;
        d2.pb(d);
        if (x >= 1)
        {
            ans += (d * x * p[x - 1]);
        }
        ans += (3 * d * p[x]);
        m /= 3;
        x++;
    }
    if (d1 > k)
    {
        cout << -1 << endl;
    }
    else if (d1 == k)
    {
        cout << ans << endl;
    }
    else
    {
        int k1 = k - d1;
        int m = n;
        int x = 0;
        for (int i = d2.size() - 1; i >= 1; i--)
        {
            int n1 = min(d2[i], k1 / 2);
            d2[i] -= n1;
            d2[i - 1] += 3 * n1;
            ans -= n1 * p[i - 1];
            k1 -= 2 * n1;
            if (k1 <= 0)
            {
                break;
            }
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    fast int t = 1;
    cin >> t;
    int q = 1;
    for (int i = 0; i < 40; i++)
    {
        p[i] = q;
        q = q * 3;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}