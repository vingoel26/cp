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

viv df;
vector<int> cat;
vector<int> v;
int m, ans = 0;

void dfs(int node, int par)
{
    for (int child : df[node])
    {
        if (child == par)
            continue;
        if (cat[child])
            v[child] = v[node] + 1;
        else
            v[child] = 0;
        if (v[child] > m)
            continue;
        if (df[child].size() == 1)
            ans++;
        dfs(child, node);
    }
}
void solve()
{
    int n;
    cin >> n >> m;
    ans = 0;
    cat.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cat[i];
    df.resize(n + 1);
    v.resize(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        df[x].push_back(y);
        df[y].push_back(x);
    }
    if (cat[1])
        v[1] = 1;
    dfs(1, -1);
    cout << ans;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}