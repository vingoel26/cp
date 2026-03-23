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
vector<pair<long long, int>> primeFactorize(long long n) {
    vector<pair<long long, int>> factors;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) { n /= 2; cnt++; }
        factors.push_back({2, cnt});
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) { n /= i; cnt++; }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}
void generateAllFactors(const vector<pair<long long, int>>& factors, vector<long long>& result, long long current = 1, int index = 0) {
    if (index == factors.size()) {
        result.push_back(current);
        return;
    }
    long long prime = factors[index].first;
    int power = factors[index].second;
    long long powerVal = 1;
    for (int i = 0; i <= power; i++) {
        generateAllFactors(factors, result, current * powerVal, index + 1);
        powerVal *= prime;
    }
}
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vpi fa=primeFactorize(a),fb=primeFactorize(b);
    sort(all(fa));
    sort(all(fb));
    map<int,int>mp;
    for(auto [p,ct]:fa){
        mp[p]+=ct;
    }
    for(auto [p,ct]:fb){
        mp[p]+=ct;
    }
    vpi tot;
    for(auto [p,ct]:mp){
        tot.pb({p,ct});
    }
    vi div;
    generateAllFactors(tot,div);
    int ans1=-1,ans2=-1;
    sort(all(div));
    for(int i=0;i<div.size();i++){
        int a1=div[i];
        int a2=(a*b)/gcd(a*b,a1);
        a1=(c/a1)*a1;
        a2=(d/a2)*a2;
        if(a1>a and a1<=c and a2>b and a2<=d){
            cout<<a1<<" "<<a2<<endl;
            return;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
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