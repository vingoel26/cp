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
void dfs(int v,vi &comp1,viv &adj,vi &vis){
    vis[v]=1;
    comp1.pb(v);
    for(auto it:adj[v]){
        if(!vis[it]){
            dfs(it,comp1,adj,vis);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    viv adj(n+1);
    for(int i=0;i<m;i++){
        int n1;
        cin>>n1;
        if(n1==0){
            continue;
        }
        vi a(n1);
        for(int j=0;j<n1;j++){
            cin>>a[j];
        }
        for(int j=0;j<n1-1;j++){
            adj[a[j]].pb(a[j+1]);
            adj[a[j+1]].pb(a[j]);
        }
    }
    viv comp;
    vi vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vi comp1;
            dfs(i,comp1,adj,vis);
            comp.pb(comp1);
        }
    }
    // for(int i=0;i<comp.size();i++){
    //     for(int j=0;j<comp[i].size();j++){
    //         cout<<comp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vi ans(n);
    for(int i=0;i<comp.size();i++){
        for(int j=0;j<comp[i].size();j++){
            ans[comp[i][j]-1]=comp[i].size();
        }
    }
    vout(ans);
    cout<<endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}