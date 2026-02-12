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

vi fact(100001);

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
const int MAX_VAL = 1000005;
vector<bool> is_prime(MAX_VAL, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_VAL; i += p)
                is_prime[i] = false;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vi a(2*n);
    vin(a);
    map<int,int>ct;
    for(int i=0;i<2*n;i++){
        ct[a[i]]++;
    }
    int ans=fact[n];
    int denom=1;
    for(auto it:ct){
        denom=(denom*fact[it.ss])%mod;
    }
    ans=(ans*binExpo(denom,mod-2,mod))%mod;
    int ans2;
    vi dp(n+1);
    dp[0]=1;
    for(auto it : ct){
        if(is_prime[it.ff]){
            for(int i=n;i>=1;i--){
                dp[i]=(dp[i]+dp[i-1]*it.ss)%mod;
            }
        }
    }
    ans=(ans*dp[n])%mod;
    cout<<ans<<endl;
}

int32_t main()
{
    fast
    sieve();
    // Precompute factorials
    fact[0] = 1;
    for(int i = 1; i <= 100000; ++i){
        fact[i] = (fact[i-1] * i) % mod;
    }

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}