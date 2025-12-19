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
#define mod 998244353
// #define mod 1000000007
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
int sum(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    if(a<0) a+=mod;
    return a;
}
int mul(int a,int b){
    return (a*b)%mod;
}
void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    int ans = 0;
    for(int i=0;i<30;i++){
        int s=0;
        int ct0=1,ct1=0;
        int lct0=0,lct1=0;
        int v=0;
        for(int j=0;j<n;j++){
            v=v^((a[j]>>i)&1);
            int r;
            if(v==0){
                r=mul(ct1,j+1);
                s=sum(s,sum(r,-lct1));
                ct0++;
                lct0=sum(lct0,j+1);
            }
            else{
                r=mul(ct0,j+1);
                s=sum(s,sum(r,-lct0));
                ct1++;
                lct1=sum(lct1,j+1);
            }
        }
        ans=sum(ans,mul(s,1LL<<i));
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