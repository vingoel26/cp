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
    int n,k;
    cin>>n>>k;
    if(n==0){
        int ans=max(0LL,k-1);
        cout<<ans<<endl;
        return;
    }
    if(k>=32) {
        cout<<__builtin_popcountl(n)+k-1<<endl;
        return;
    }
    int l=32;
    vector<vector<vector<vector<int>>>> dp(l+1,vector<vector<vector<int>>>(k+1,vector<vector<int>>(2,vector<int>(l+1,1e9))));
    dp[0][0][0][0]=0;
    for(int i=0;i<l;i++) {
        int b=(n>>i)&1;
        for(int j=0;j<=k;j++) {
            for(int i1=0;i1<=1;i1++) {
                for(int j1=0;j1<=l;j1++) {
                    if(dp[i][j][i1][j1]==1e9){
                        continue;
                    }
                    int s=i1+b;
                    int o=s&1;
                    int ni1=s/2;
                    dp[i+1][j][ni1][j1+o]=1;
                    if(j<k){
                        int s=i1+b+1;
                        int o=s&1;
                        int ni1=s/2;
                        dp[i+1][j+1][ni1][j1+o]=1;
                    }
                }
            }
        }
    }
    int ans=0;
    int k1=__builtin_popcountl(n);
    for(int i=0;i<=l;i++) {
        for(int j=0;j<=k;j++) {
            for(int i1=0;i1<=1;i1++) {
                if (dp[l][j][i1][i]==1) {
                    int tot=i+i1;
                    int ans1=k1+k-tot;
                    ans=max(ans,ans1);
                }
            }
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