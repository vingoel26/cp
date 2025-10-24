#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                  \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a)                 \
    for (int i = 0; i < n; ++i) \
    {                           \
        cout << a[i] << ' ';    \
    }
#define pb push_back
#define ff first
#define ss second
#define viv vector<vector<int>>
#define nah cout << "NO\n";
#define yah cout << "YES\n";
#define be begin()
#define en end()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007
using namespace std;

vi fact(200001);

int binExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int res = binExpo(a, b / 2, m);
        return (res * res) % m;
    }
    else
    {
        return (a * binExpo(a, b - 1, m)) % m;
    }
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod - 2, mod)) % mod;
    res = (res * binExpo(fact[n - r], mod - 2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/
const int N = 2e5 + 10;
vi spf(N + 1);
void sieve()
{
    for (int i = 2; i <= N; ++i)
        spf[i] = i;
    for (int i = 2; i * i <= N; ++i)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vi getPrimeFactors(int n)
{
    vi res;
    while (n > 1)
    {
        int p = spf[n];
        res.pb(p);
        while (n % p == 0)
            n /= p;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    vin(a);
    vin(b);
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y)
         { return b[x] < b[y]; });
    int ans = b[ord[0]] + b[ord[1]];
    map<int, int> ct;
    for (int i = 0; i < n; ++i)
    {
        vi pf = getPrimeFactors(a[i]);
        for (int x : pf)
        {
            if (ct[x] > 0)
            {
                ans = 0;
            }
            ct[x]++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        vi pf = getPrimeFactors(a[i]);
        for (int x : pf)
        {
            ct[x]--;
        }
        vi pf2 = getPrimeFactors(a[i] + 1);
        for (int x : pf2)
        {
            if (ct[x] > 0)
            {
                ans = min(ans, b[i]);
            }
        }
        for (int x : pf)
        {
            ct[x]++;
        }
    }
    int idx = ord[0];
    vi q;
    for (int i = 0; i < n; ++i)
    {
        if (i == idx)
        {
            continue;
        }
        vi pf = getPrimeFactors(a[i]);
        for (int x : pf)
        {
            q.pb(x);
        }
    }
    for (int x : q)
    {
        int k = x - (a[idx] % x);
        if (k == x)
            k = 0;
        ans = min(ans, k * b[idx]);
    }
    cout << ans << endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    // fact[0] = 1;
    // for(int i = 1; i <= 200000; ++i){
    //     fact[i] = (fact[i-1] * i) % mod;
    // }
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}