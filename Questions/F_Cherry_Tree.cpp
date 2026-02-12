#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                         \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cin >> a[i];                   \
    }
#define vout(a)                        \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cout << a[i] << ' ';           \
    }
#define pb push_back
#define ff first
#define ss second
#define viv vector<vector<int>>
#define nah cout << "NO\n";
#define yah cout << "YES\n";
#define pt(x) cout << x << endl;
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
// #define mod 1000000007
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vi fact(200001);

int binExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int res = binExpo(a, b / 2, m);
        return (res * res) % m;
    }
    else
    {
        return (a * binExpo(a, b - 1, m)) % m;
    }
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod - 2, mod)) % mod;
    res = (res * binExpo(fact[n - r], mod - 2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

int n;
viv adj(200001);
bool ans;

int dfs(int u, int p)
{
    vector<int> child;
    int cnt = 0;
    for (auto v : adj[u])
        if (v != p)
        {
            cnt++;
            auto t = dfs(v, u);
            if (t != 0)
            {
                child.push_back(t);
            }
        }

    if (child.size() > 1)
    {
        ans = true;
        return 0;
    }
    int type;
    if(cnt==0){
        type=0;
    }
    else{
        type=(cnt+2)%3;
    }
    vector<int> ord;
    if (type)
    {
        ord.push_back(type);
    }
    if (!child.empty())
    {
        ord.push_back(child[0]);
    }
    if (ord.size() == 2 and ord[0] + ord[1] != 3)
    {
        ans = true;
        return 0;
    }
    if (ord.size() >= 1)
    {
        return ord[0];
    }
    return 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = false;
    int res = dfs(1, 1);
    if (res == 2)
    {
        ans = true;
    }
    if(ans){
        yah
    }
    else{
        nah
    }
}

int32_t main()
{
    fast
        // Precompute factorials
        // fact[0] = 1;
        // for(int i = 1; i <= 200000; ++i){
        //     fact[i] = (fact[i-1] * i) % mod;
        // }

        int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}