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

void solve()
{
    int n,d;
    cin>>n>>d;
    vi a(n+1),b(n+1),posa(n+1),posb(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        posa[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        posb[b[i]]=i;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(posa[b[i]]>posa[b[i+1]]){
            ans+=n;
        }
    }
    ans+=posa[b[n]]-(n);
    cout<<ans<<endl;
    for(int i=0;i<d-1;i++){
        int c,x,y;
        cin>>c>>x>>y;
        set<int> s;
        if (c==1){
            int i1 = posb[a[x]], i2 = posb[a[y]];
            if (i1>1) {
                s.insert(i1-1);
            }
            if (i1<n) {
                s.insert(i1);
            }
            if (i2>1) {
                s.insert(i2-1);
            }
            if (i2<n) {
                s.insert(i2);
            }
        } 
        else if (c == 2) {
            if (x>1) {
                s.insert(x-1);
            }
            if (x<n) {
                s.insert(x);
            }
            if (y>1) {
                s.insert(y-1);
            }
            if (y<n) {
                s.insert(y);
            }
        }
        for (int idx : s) {
            if (posa[b[idx]]>posa[b[idx+1]]) {
                ans-=n;
            }
        }
        ans-=posa[b[n]];
        if (c==1) {
            swap(posa[a[x]], posa[a[y]]);
            swap(a[x], a[y]);
        } 
        else if (c==2) {
            swap(posb[b[x]], posb[b[y]]);
            swap(b[x], b[y]);
        }
        
        for (int idx : s) {
            if (posa[b[idx]] > posa[b[idx+1]]){ 
                ans += n;
            }
        }
        ans+=posa[b[n]];
        cout<<ans<<endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}