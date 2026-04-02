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
    bool k=true;
    for(int u=1;u<=n;u++){
        if (adj[u].size()<4){
            continue;
        }
        vi visited(n+1,0);
        vi parent(n+1,-1);
        vi root(n+1,-1);
        queue<int> q;
        visited[u]=1;
        for(int v:adj[u]){
            visited[v]=1;
            root[v]=v;
            parent[v]=u;
            q.push(v);
        }
        bool pos=false;
        int n1=-1,n2=-1;
        while(!q.empty()){
            int u1=q.front();
            q.pop();
            for(int v:adj[u1]){
                if(v==u){
                    continue;
                }
                if(!visited[v]){
                    visited[v]=1;
                    root[v]=root[u1];
                    parent[v]=u1;
                    q.push(v);
                } 
                else if(root[v]!=root[u1]){
                    n1=u1;
                    n2=v;
                    pos=true;
                    break;
                }
            }
            if(pos){
                break;
            }
        }
        if(pos){
            vpi ans;
            int u1=n1;
            while(u1!=root[n1]){
                ans.pb({u1,parent[u1]});
                u1=parent[u1];
            }
            u1=n2;
            while(u1!=root[n2]){
                ans.pb({u1,parent[u1]});
                u1=parent[u1];
            }
            ans.pb({n1,n2});
            ans.pb({root[n1],u}); 
            ans.pb({root[n2],u});
            int ct=0;
            for(int v:adj[u]){
                if(v!=root[n1] and v!=root[n2]){
                    ans.pb({u,v});
                    ct++;
                    if(ct==2){
                        break;
                    }
                }
            }
            yah
            k=false;
            cout<<ans.size()<<endl;
            for(auto [u,v]:ans){
                cout<<u<<" "<<v<<endl;
            }
            return;
        }
    }
    if(k) nah
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