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
    int n,k;
    cin>>n>>k;
    vi a(n);
    vin(a);
    for(int i=0;i<n;i++){
        if(a[i]<=k){
            a[i]=1;
        }
        else{
            a[i]=-1;
        }
    }
    // for(int i=1;i<n;i++){
    //     a[i]=a[i-1]+a[i];
    // }
    // vout(a);
    // cout<<endl;
    vi pr(n+1),sf(n+1);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+a[i-1];
    }
    for(int i=n-1;i>=0;i--){
        sf[i]=sf[i+1]+a[i];
    }
    int p=n+1,q=-1;
    for(int i=1;i<=n;i++){
        if(pr[i]>=0){
            p=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(sf[i]>=0){
            q=i+1;
            break;
        }
    }
    if(p+1<q){
        yah
        return;
    }
    vi mxprsf(n+1),mxsfpr(n+1);
    mxprsf[n]=pr[n];
    for(int i=n-1;i>=1;i--){
        mxprsf[i]=max(pr[i],mxprsf[i+1]);
    }
    mxsfpr[0]=sf[0];
    for(int i=1;i<n;i++){
        mxsfpr[i]=max(sf[i],mxsfpr[i-1]);
    }
    for(int i=1;i<=n;i++){
        if(i!=n and pr[i]>=0 and mxprsf[i+1]>=pr[i]){
            yah
            return;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i!=0 and sf[i]>=0 and mxsfpr[i-1]>=sf[i]){
            yah
            return;
        }
    }
    nah
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