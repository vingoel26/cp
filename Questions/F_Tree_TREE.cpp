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

void solve()
{
    int n,k;
    cin>>n>>k;
    viv adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi par(n+1,-5);
    vi d;
    stack<int> st;
    st.push(1);
    par[1]=-1;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        d.pb(u);
        for(int nodes : adj[u]){
            if(par[nodes]==-5){
                par[nodes]=u;
                st.push(nodes);
            }
        }
    }
    vi slen(n+1);
    for(int i=n-1;i>=0;i--){
        int u=d[i];
        slen[u]=1;
        for(int v : adj[u]){
            if(par[v]==u){
                slen[u]+=slen[v];
            }
        }
    }
    int ans=0;
    int r=n-k;
    for(int i=1;i<=n;i++){
        int ct=1;
        for(int v : adj[i]){
            int c;
            if(par[v]==i){
                c=slen[v];
            }
            else{
                c=n-slen[i];
            }
            if(c<=r){
                ct+=c;
            }
        }
        ans+=ct;
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