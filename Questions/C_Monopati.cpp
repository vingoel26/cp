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

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    vi b(n);
    vin(b);
    vi prmn(n+1,1e9),prmx(n+1,0);
    for(int i=1;i<=n;i++){
        prmn[i]=min(prmn[i-1],a[i-1]);
        prmx[i]=max(prmx[i-1],a[i-1]);
    }
    vi sfmn(n+2,1e9),sfmx(n+2,0);
    for(int i=n;i>=1;i--){
        sfmn[i]=min(sfmn[i+1],b[i-1]);
        sfmx[i]=max(sfmx[i+1],b[i-1]);
    }
    vi c(2*n+5,1e9);
    for(int i=1;i<=n;i++){
        int l=min(prmn[i],sfmn[i]);
        int r=max(sfmx[i],prmx[i]);
        c[l]=min(c[l],r);
    }
    vi ans1(2*n+5,1e9);
    for(int i=2*n;i>=1;i--){
        ans1[i]=min(ans1[i+1],c[i]);
    }
    int ans=0;
    for(int i=1;i<=2*n;i++){
        if(ans1[i]<=2*n){
            ans+=2*n-ans1[i]+1;
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