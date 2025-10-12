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
#define en end()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

void solve()
{
    inp(n);
    inp(m);
    vi a(n + 2, 0);
    vi b(n + 2, 0);
    vi mk(n + 2, 0);
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        mk[i] = 0;
    }
    sort(a.be + 2, a.be + n + 1);
    sort(b.be + 1, b.be + n + 1);
    int i = 2, j = 1;
    while (i <= n && j <= n)
    {
        if (a[i] < b[j])
        {
            mk[j] = 1;
            i++, j++;
        }
        else
        {
            j++;
        }
    }
    vi v;
    for (int i = 1; i <= n; i++)
    {
        if (mk[i] == 0)
            v.pb(b[i]);
    }
    int mx = v[v.size()-1];
    int inia = n - i + 2;
    int ans = inia * m - min((mx - 1), m);
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