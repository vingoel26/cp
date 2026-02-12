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
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
vector<int> spf; // Smallest prime factor

// Precompute smallest prime factors up to maxN
void computeSPF(int maxN) {
    spf.resize(maxN + 1);
    for (int i = 0; i <= maxN; ++i) spf[i] = i;
    for (int i = 2; i * i <= maxN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Optimized factorization using SPF
set<int> primeFactors(int n) {
    set<int> factors;
    while (n > 1) {
        factors.insert(spf[n]);
        n /= spf[n];
    }
    return factors;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/
vector<char> prime;
void solve()
{
    int n;
    cin>>n;
    vi ans1(n);
    vi ans2(n);
    vi a(n);
    vin(a);
    for(int i=0;i<n;i++){
        if(prime[a[i]-2]){
            ans1[i]=-1;
            ans2[i]=-1;
        }
        else if((a[i]&(a[i]-1))==0){
            ans1[i]=-1;
            ans2[i]=-1;
        }
        else{
            set<int> fact=primeFactors(a[i]);
            if(fact.size()==1){
                ans1[i]=-1;
                ans2[i]=-1;
            }
            else{
                int p=(*fact.begin());
                int p1=1;
                for(auto it : fact){
                    p1*=it;
                }
                ans1[i]=p;
                ans2[i]=p1/p;
            }
        }
    }
    vout(ans1);
    cout<<endl;
    vout(ans2);
    cout<<endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    // fact[0] = 1;
    // for(int i = 1; i <= 200000; ++i){
    //     fact[i] = (fact[i-1] * i) % mod;
    // }
    prime=segmentedSieve(2,10000000);
    computeSPF(10000001);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}