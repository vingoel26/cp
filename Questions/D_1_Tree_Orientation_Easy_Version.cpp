#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
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
void bfs(vector<vector<int>>& adj, int src, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
void bfs1(vector<vector<int>>& adj, int src, vector<int>& visited) {
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}
vector<vector<int>> getComponents(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<vector<int>> res;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            bfs(adj, i, visited, component);
            res.push_back(component);
        }
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    vector<string> a(n);
    vin(a);
    for(int i=0;i<n;i++){
        if(a[i][i]!='1'){
            nah
            return;
        }
    }
    vi ct(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='1'){
                ct[i]++;
            }
        }
    }
    vpi ctp;
    for(int i=0;i<n;i++){
        ctp.pb({ct[i],i});
    }
    sort(rall(ctp));
    vpi e;
    for(int i=0;i<n;i++){
        vi vis(n,0);
        for(auto it : ctp){
            int v=it.ss;
            if(i==v or a[i][v]=='0'){
                continue;
            }
            if(!vis[v]){
                e.pb({i,v});
                if(e.size()>=n) {
                    nah
                    return;
                }
                for(int j=0;j<n;j++){
                    if(a[v][j]=='1'){
                        vis[j]=1;
                    }
                }
            }
        }
    }
    if(e.size()!=n-1){
        nah
        return;
    }
    viv adj(n);
    for(auto [u,v]:e){
        adj[u].pb(v);
    }
    for(int i=0;i<n;i++){
        vi vis(n,0);
        bfs1(adj,i,vis);
        for(int j=0;j<n;j++){
            if(a[i][j]=='1' and vis[j]!=1){
                nah
                return;
            }
            if(a[i][j]=='0' and vis[j]!=0){
                nah
                return;
            }
        }
    }
    for(auto [u,v]:e){
        adj[v].pb(u);
    }
    viv comp=getComponents(adj);
    if(comp.size()>1 or comp[0].size()!=n){
        nah
        return;
    }
    yah
    for(auto [u,v]:e){
        cout<<u+1<<" "<<v+1<<endl;
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