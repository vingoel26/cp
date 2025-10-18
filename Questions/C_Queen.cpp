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
void dfs(int node, viv &adj, vector<bool> &visited, set<int> &ans, vi &b){
    visited[node] = true;
    int ct=0,ct1=1;
    if(b[node-1]==1){
        ct=1;
    }
    for(auto &child : adj[node]){
        if(!visited[child]){
            dfs(child, adj, visited, ans, b);
            if(b[child-1]==1){
                ct++;
            }
            ct1++;
        }
    }
    if(ct==ct1){
        ans.insert(node);
    }
}
void solve()
{
    int n;
    cin>>n;
    vi a(n),b(n);
    int r=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(a[i]==-1 and b[i]==0){
            r=i+1;
        }
    }
    viv adj(n+1);
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            continue;
        }
        adj[a[i]].pb(i+1);
        adj[i+1].pb(a[i]);
    }
    vector<bool> visited(n+1,false);
    set<int> ans;
    dfs(r,adj,visited,ans,b);
    // cout<<ans.size()<<endl;
    ans.erase(r);
    if(ans.size()==0){
        cout<<-1<<endl;
        return;
    }
    for(auto &it:ans){
        cout<<it<<" ";
    }
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