#include <bits/stdc++.h>
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
#define INF 1e18
#define mod 998244353
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
    viv city(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>city[i][j];
        }
    }
    vi ca(n),cb(n);
    for(int i=0;i<n;i++){
        cin>>ca[i];
    }
    for(int i=0;i<n;i++){
        cin>>cb[i];
    }
    viv dp(n,vi(2,INF));
    dp[0][0]=0;
    dp[0][1]=ca[0];
    for(int i=1;i<n;i++){
        for(int x=0;x<2;x++){
            for(int y=0;y<2;y++){
                bool q=true;
                for(int j=0;j<n;j++){
                    q&=(city[i-1][j]+y!=city[i][j]+x);
                }
                if(q){
                    if(x==0){
                        dp[i][x]=min(dp[i][x],dp[i-1][y]);
                    } else {
                        dp[i][x]=min(dp[i][x],dp[i-1][y]+ca[i]);
                    }
                }
            }
        }
    }
    int ans1=min(dp[n-1][0],dp[n-1][1]);
    viv dp1(n,vi(2,INF));
    dp1[0][0]=0;
    dp1[0][1]=cb[0];
    for(int i=1;i<n;i++){
        for(int x=0;x<2;x++){
            for(int y=0;y<2;y++){
                bool q=true;
                for(int j=0;j<n;j++){
                    q&=(city[j][i-1]+y!=city[j][i]+x);
                }
                if(q){
                    if(x==0){
                        dp1[i][x]=min(dp1[i][x],dp1[i-1][y]);
                    } else {
                        dp1[i][x]=min(dp1[i][x],dp1[i-1][y]+cb[i]);
                    }
                }
            }
        }
    }
    int ans2=min(dp1[n-1][0],dp1[n-1][1]);
    if(ans1==INF or ans2==INF){
        pt(-1)
    } 
    else {
        pt(ans1+ans2)
    }
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