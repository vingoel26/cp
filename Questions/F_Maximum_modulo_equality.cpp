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
using namespace std;

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

viv stGCD;

void solve()
{
    int n,q;
    cin>>n>>q;
    vi a(n);
    vin(a);
    stGCD.clear();
    vi b;
    for(int i=1;i<n;i++){
        b.pb(abs(a[i]-a[i-1]));
    }
    stGCD.resize(20,vi(b.size(), 1));
    for(int i=0;i<b.size();i++){
        stGCD[0][i]=b[i];
    }
    for(int i=1;i<20;i++){
        for(int j=0;j+(1<<(i-1))<b.size();j++){
            stGCD[i][j]=__gcd(stGCD[i-1][j], stGCD[i-1][j+(1<<(i-1))]);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<0<<" ";
            continue;
        }
        l--;r-=2;
        int k=__lg(r-l+1);
        int gcd=__gcd(stGCD[k][l], stGCD[k][r-(1<<k)+1]);
        cout<<gcd<<" ";
    }
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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}