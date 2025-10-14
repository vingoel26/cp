#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
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
#define fast \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007
using namespace std;

vi fact(1001);

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
    vi a(n);
    vin(a);
    vi mp(n+1,0);
    for(int i = 0; i < n; ++i){
        mp[a[i]]++;
    }
    sort(rall(a));
    int n1=mp[a[k-1]];
    int s=0;
    for(int i=n; i > a[k-1]; --i){
        s+= mp[i];
    }
    // cout<<a[k-1]<<' ';
    // cout<<s<<endl;
    s=k-s;
    // cout<<n1<<' '<<s<<'\n';
    int ans = 1*nCr(n1, s);
    cout << ans << '\n';
    return;
}

int32_t main()
{
    fast
    fact[0] = 1;
    for(int i = 1; i <= 1000; ++i){
        fact[i] = (fact[i-1] * i) % mod;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}