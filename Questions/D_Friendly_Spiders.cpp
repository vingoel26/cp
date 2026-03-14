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
const int MAXA = 300005;
int spf[MAXA];
void compute_spf() {
    for (int i = 2; i < MAXA; i++) spf[i] = i;
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    int s,t;
    cin>>s>>t;
    if(s==t){
        cout<<1<<endl;
        cout<<s<<endl;
        return;
    }
    viv adj(n+MAXA+1);
    for(int i=0;i<n;i++){
        int v=a[i];
        while(v>1){
            int p=spf[v];
            adj[i+1].pb(n+p);
            adj[n+p].pb(i+1);
            while(v%p==0){
                v/=p;
            }
        }
    }
    vi dis(n+MAXA+1,-1),par(n+MAXA+1,-1);
    queue<int>q;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==t){
            break;
        }
        for(auto v : adj[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(dis[t]==-1){
        cout<<-1<<endl;
        return;
    }
    vi ans;
    while(t!=-1){
        if(t<=n){
            ans.pb(t);
        }
        t=par[t];
    }
    reverse(all(ans));
    cout<<ans.size()<<endl;
    vout(ans)
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
    compute_spf();
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}