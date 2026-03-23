#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
// #define mod 998244353
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
int dfs(int u, int p, viv& adj, vi& sub_size) {
    sub_size[u] = 1; 
    for (int v : adj[u]) {
        if (v != p) {
            sub_size[u] += dfs(v, u, adj, sub_size);
        }
    }
    return sub_size[u];
}
void solve()
{
    int n;
    cin>>n;
    viv adj(n+1);
    vpi e;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e.pb({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int m;
    cin>>m;
    vector<int>ms;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        ms.pb(x);
    }
    while(ms.size()<n-1){
        ms.pb(1);
    }
    sort(all(ms));
    if(ms.size()>n-1){
        while(ms.size()!=n-1){
            ms[ms.size()-2]=(ms[ms.size()-2]*ms[ms.size()-1])%mod;
            ms.pop_back();
        }
    }
    vi sz(n+1);
    dfs(1,0,adj,sz);
    vector<int>ms1;
    for(int i=0;i<n-1;i++){
        int mn=min(sz[e[i].ff],sz[e[i].ss]);
        ms1.pb(mn*(n-mn));
    }
    int ans=0;
    sort(all(ms1));
    // sort(all(ms));
    for(int i=n-2;i>=0;i--){
        ans=(ans+((ms1[i]%mod)*ms[i])%mod)%mod;
    }
    cout<<ans<<endl;
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