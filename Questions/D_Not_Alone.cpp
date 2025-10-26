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
    int ans=1e15;
    vi dp(n,1e15);
    dp[1]=abs(a[0]-a[1]);
    dp[2]=max(a[0],max(a[1],a[2]))-min(a[0],min(a[1],a[2]));
    for(int i=3;i<n;i++){
        dp[i]=min(dp[i-2]+abs(a[i-1]-a[i]),dp[i-3]+max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2])));
    }
    ans=min(ans,dp[n-1]);
    for(int i=0;i<n-1;i++){
        swap(a[i],a[i+1]);
    }
    dp[1]=abs(a[0]-a[1]);
    dp[2]=max(a[0],max(a[1],a[2]))-min(a[0],min(a[1],a[2]));
    for(int i=3;i<n;i++){
        dp[i]=min(dp[i-2]+abs(a[i-1]-a[i]),dp[i-3]+max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2])));
    }
    ans=min(ans,dp[n-1]);
    for(int i=0;i<n-1;i++){
        swap(a[i],a[i+1]);
    }
    dp[1]=abs(a[0]-a[1]);
    dp[2]=max(a[0],max(a[1],a[2]))-min(a[0],min(a[1],a[2]));
    for(int i=3;i<n;i++){
        dp[i]=min(dp[i-2]+abs(a[i-1]-a[i]),dp[i-3]+max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2])));
    }
    ans=min(ans,dp[n-1]);
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