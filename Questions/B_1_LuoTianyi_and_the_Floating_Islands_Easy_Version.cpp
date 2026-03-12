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
#define up upper_bound
#define low lower_bound
#define mod 1000000007
// #define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vi fact(200005);

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

int modAdd(int a, int b, int mod1) {
    return (a % mod + b % mod) % mod;
}
int modSub(int a, int b, int mod1) {
    return ((a % mod - b % mod) + mod) % mod;
}
int modMul(int a, int b, int mod1) {
    return ((a % mod) * (b % mod)) % mod;
}
int modDiv(int a, int b, int mod1) {
    return modMul(a, binExpo(b,mod-2, mod), mod);
}
 
void dfs(int node,viv &adj,int par,vector<int> &sub){
    sub[node]=1;
    for (auto child : adj[node]){
        if (child==par){
            continue;
        }
        dfs(child,adj,node,sub);
        sub[node]+=sub[child];
    }
}

int cal(int n, int node, viv &adj, int par, vector<int> &sub) {
    int ans = 0;
    for (auto child : adj[node]) {
        if (child == par){
            continue;
        }
        int a = sub[child], b = n - a;
        int x = modMul(a,b,mod);
        x = modMul(x, binExpo(nCr(n,2),mod-2,mod), mod);
        ans = modAdd(ans, x, mod);
        ans = modAdd(ans, cal(n, child, adj, node, sub), mod);
    }
    return ans;
}

void solve() {
    int n,k;
    cin>>n>>k;
    viv adj(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(k==1 or k==3){
        cout<<1<<endl;
        return;
    } 
    vi sub(n+1);
    dfs(1,adj,0,sub);
    int a=cal(n,1,adj,0,sub);
    a++;
    a%=mod;
    cout<<a<<endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    fact[0] = 1;
    for(int i = 1; i <= 200004; ++i){
        fact[i] = (fact[i-1] * i) % mod;
    }

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}