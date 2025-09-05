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
    string s;
    cin >> n >> k >> s;
    viv cnt(n + 1, vi(26, 0));
    for (int i = 0; i < n; ++i)
    {
        cnt[i % k][s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        int u=i,v=k-i-1;
        int s = 0, mx = 0;
        for (int j = 0; j < 26; ++j)
        {
            s += cnt[u][j] + cnt[v][j];
            mx = max(mx, cnt[u][j] + cnt[v][j]);
        }
        ans += s-mx;
    }
    cout << ans / 2 << endl;
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