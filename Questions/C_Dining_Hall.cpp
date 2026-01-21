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
// int n, m;
//     long long T;
//     cin >> n >> m >> T;
//     vector<long long> a(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     vector<long long> P(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         P[i] = P[i - 1] + a[i];
//     }
//     vector<int> B(m);
//     for (int i = 0; i < m; i++) {
//         cin >> B[i];
//     }
//     long long ans = 0;
//     for (int i = 1; i <= n; i++) {
//         long long bestForI = 0;
//         {
//             auto it = upper_bound(B.begin(), B.end(), i);
//             if (it != B.begin()) {
//                 int b = *(it - 1);
//                 long long cost = P[i] - P[b - 1];
//                 if (cost <= T) {
//                     long long ct = i - b + 1;
//                     long long extra = (T - cost) / a[i];
//                     long long bst1 = ct + extra;
//                     bestForI = max(bestForI, bst1);
//                 }
//             }
//         }
//         {
//             auto it = lower_bound(B.begin(), B.end(), i);
//             if (it != B.end()) {
//                 int b = *it;
//                 long long cost = P[b] - P[i - 1];
//                 if (cost <= T) {
//                     long long ct = b - i + 1;
//                     long long extra = (T - cost) / a[i];
//                     long long bst1 = ct + extra;
//                     bestForI = max(bestForI, bst1);
//                 }
//             }
//         }
//         ans = max(ans, bestForI);
//     }
//     cout << ans << endl;
void solve()
{
    int n,m,t;
    cin>>n>>m>>t;
    vi a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vi p(n+1,0);
    for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    vi b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int bst=0;
        {
            auto it=upper_bound(all(b),i);
            if(it!=b.begin()){
                int bb=*(it-1);
                int cost=p[i]-p[bb-1];
                if(cost<=t){
                    int ct=i-bb+1;
                    int extra=(t-cost)/a[i];
                    int bst1=ct+extra;
                    bst=max(bst,bst1);
                }
            }
        }
        {
            auto it=lower_bound(all(b),i);
            if(it!=b.end()){
                int bb=*it;
                int cost=p[bb]-p[i-1];
                if(cost<=t){
                    int ct=bb-i+1;
                    int extra=(t-cost)/a[i];
                    int bst1=ct+extra;
                    bst=max(bst,bst1);
                }
            }
        }
        ans=max(ans,bst);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}