#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < a.size(); ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
    for (int i = 0; i < a.size(); ++i) \
    {                           \
        cout << a[i] << ' ';    \
    }
#define pb push_back
#define ff first
#define ss second
#define viv vector<vector<int>>
#define nah cout << "NO\n";
#define yah cout << "YES\n";
#define pt(x) cout<<x<<endl;
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
#define vppi vector<vector<pair<int,int>>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007
#define mod 998244353
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vi fact(200001);

int binExpo(int a, int b, int m){
    if(b == 0) return 1;
    if(b % 2 == 0){
        int res = binExpo(a, b/2, m);
        return (res * res) % m;
    } else {
        return (a * binExpo(a, b-1, m)) % m;
    }
}

int nCr(int n, int r){
    if(r > n) return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod-2, mod)) % mod;
    res = (res * binExpo(fact[n-r], mod-2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/
void dfs_subtree(int u, const viv& adj, vi& sz, vi& vis) {
    vis[u] = 1;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs_subtree(v, adj, sz, vis);
            sz[u] += sz[v];
        }
    }
}
void dfs_tarjan(int u, int p, const viv& adj, vi& tin, vi& low, int& timer, int& max_cut, const vi& sz, int n) {
    tin[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (tin[v] == 0) { 
            dfs_tarjan(v, u, adj, tin, low, timer, max_cut, sz, n);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                int cut_contribution = sz[v] * (n - sz[v]);
                max_cut = max(max_cut, cut_contribution);
            }
        } else if (v != p) { 
            low[u] = min(low[u], tin[v]);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    viv adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi sz(n+1),vis(n+1,0);
    dfs_subtree(1,adj,sz,vis);
    vi tin(n+1,0),low(n+1,0);
    int tim=1,ans=0;
    dfs_tarjan(1,0,adj,tin,low,tim,ans,sz,n);
    cout<<n*(n-1)/2-ans<<endl;
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