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
// #define mod 998244353
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
vi fact(200001);
vi invfact(200001);
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
    res = (res * invfact[r]) % mod;
    res = (res * invfact[n-r]) % mod;
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
    int n;
    cin>>n;
    vi b(n);
    vin(b);
    vi cnt(29,0);
    for(int i=n-1;i>=0;i--){
        for(int l=0;l<29;l++){
            if((b[i]>>l)&1){
                cnt[l]=i+1;
                for(int j=0;j<=i;j++){
                    int sub=(nCr(i+1,j+1)*(1LL<<l))%mod;
                    b[j]-=sub;
                    if(b[j]<0) b[j]+=mod;
                }
            }
        }
    }
    vi a(n,0);
    for(int l=0;l<29;l++){
        for(int i=0;i<cnt[l];i++){
            a[i]|=(1LL<<l);
        }
    }
    vout(a);
    cout<<endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 200000; ++i){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[200000] = binExpo(fact[200000], mod-2, mod);
    for(int i = 199999; i >= 1; --i){
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}