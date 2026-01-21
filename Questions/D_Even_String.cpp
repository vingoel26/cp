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
// #define mod 1000000007
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vi fact(200001);
vi fact_inv(200001);

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
    vi a(26);
    vin(a);
    int s=accumulate(all(a),0LL);
    viv dp(27,vi(s/2+1,0));
    dp[0][0]=1;
    for(int i=1;i<=26;i++){
        for(int j=0;j<=s/2;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1] and a[i-1]>0){
                dp[i][j]+=dp[i-1][j-a[i-1]];
            }
        }
    }
    int k=dp[26][s/2];
    int ans=(fact[s/2]*fact[s-s/2])%mod;
    ans=(ans*k)%mod;
    for(int i=0;i<26;i++){
        ans=(ans*fact_inv[a[i]])%mod;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    fact[0] = 1;
    fact_inv[0] = 1;
    for(int i = 1; i <= 200000; ++i){
        fact[i] = (fact[i-1] * i) % mod;
        fact_inv[i] = binExpo(fact[i], mod-2, mod);
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}