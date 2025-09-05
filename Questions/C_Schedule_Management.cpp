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
    int k, n;
    cin >> k >> n;
    vi a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int l = 0, r = 2 * n;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int ct1 = 0, ct2 = 0;
        for (int i = 1; i <= k; i++)
        {
            if (mid >= m[i])
            {
                ct1 += (mid - m[i]) / 2;
            }
            else
            {
                ct2 += m[i] - mid;
            }
        }
        if (ct2 <= ct1)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {

            l = mid + 1;
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