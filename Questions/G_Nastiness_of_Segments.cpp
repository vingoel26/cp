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
const int INF = 1e9;
struct SegTree {
    int n;
    vector<int> t;
    SegTree() { n = 0; }
    SegTree(int _n) { init(_n); }
    void init(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        t.assign(2 * n, INF);
    }
    void build(const vector<int>& a) {
        int m = (int)a.size() - 1; 
        init(m);
        for (int i = 1; i <= m; ++i) t[n + i - 1] = a[i];
        for (int i = n - 1; i >= 1; --i) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    void point_update(int pos, int val) {
        int idx = n + pos - 1;
        t[idx] = val;
        idx >>= 1;
        while (idx >= 1) {
            t[idx] = min(t[idx<<1], t[idx<<1|1]);
            idx >>= 1;
        }
    }

    int range_min(int l, int r) {
        if (l > r) return INF;
        l = l + n - 1;
        r = r + n - 1;
        int res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, t[l++]);
            if (!(r & 1)) res = min(res, t[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};
void solve()
{
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    SegTree st;
    st.build(a);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i,x;
            cin>>i>>x;
            st.point_update(i,x);
        }
        else if(t==2){
            int l,r;
            cin>>l>>r;
            int l1=0,r1=r-l;
            int ans=-1;
            while(l1<=r1){
                int m=(l1+r1)/2;
                int mn=st.range_min(l,l+m);
                if(mn<=m){
                    ans=m;
                    r1=m-1;
                }
                else{
                    l1=m+1;
                }
            }
            if(ans==-1){
                cout<<0<<endl;
            }
            else{
                int mn=st.range_min(l,l+ans);
                if(mn==ans){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
        }
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