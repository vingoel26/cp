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
    int n,x;
    cin>>n>>x;
    vi a(n);
    vin(a);
    vi divs;
    vi vis(1e6+5),divi(1e6+5);
    for(int i=1;i*i<=x;i++){
        if(!(x%i)){
            divi[i]=1;
            divs.pb(i);
            if(i*i!=x){
                divs.pb(x/i);
                divi[x/i]=1;
            }
        }
    }
    int ans=1;
    vis[1]=1;
    vi curdiv={1};
    for(int i=0;i<n;i++){
        int k=a[i];
        if(!divi[a[i]]){
            continue;
        }
        vi curdiv1;
        bool q=false;
        for(auto it : curdiv){
            if(it*a[i]<=x and divi[it*a[i]] and !vis[it*a[i]]){
                curdiv1.pb(it*a[i]);
                vis[it*a[i]]=1;
                if(it*a[i]==x){
                    q=true;
                }
            }
        }
        for(int j=0;j<curdiv1.size();j++){
            curdiv.pb(curdiv1[j]);
        }
        if(q){
            ans++;
            for(int j=0;j<curdiv.size();j++){
            vis[curdiv[j]]=0;
            }
            vis[1]=0;
            vis[a[i]]=0;
            curdiv={1,a[i]};
        }
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