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
    vi s(n), u(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    viv c(n);
    for (int i = 0; i < n; i++)
    {
        c[s[i]-1].push_back(u[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sort(c[i].begin(), c[i].end(), greater<int>());
    }
    viv pr(n, vi(1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int x : c[i])
        {
            pr[i].push_back(pr[i].back() + x);
        }
    }
    vi ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= c[i].size(); ++k)
        {
            ans[k - 1] += pr[i][c[i].size() / k * k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout<<endl;
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