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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(all(a));
    vi px(n);
    px[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        px[i] = px[i - 1] + a[i];
    }
    if (x - px[0] < 0)
    {
        cout << 0 << endl;
        return;
    }
    vi ans;
    int h = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (x - px[i] < 0)
        {
            continue;
        }
        if (!h)
            h = i + 1;
        ans.push_back((x - px[i]) / (i + 1) + 1);
    }

    int ans1 = 0;
    int q = 0;
    for (int i = 0; i < ans.size(); ++i)
    {
        ans1 += (ans[i] - q) * h;
        h--;
        q = ans[i];
    }
    cout << ans1 << endl;
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