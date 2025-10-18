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
    string s,s1,s2;
    cin>>s>>s1>>s2;
    int n=s.size(),m=s1.size();
    viv dp(n+1,vi(m+1,1e9));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        if(s[i]==s2[i]){
            dp[i+1][0]=dp[i][0];
        }
        else{
            dp[i+1][0]=dp[i][0]+1;
        }
    }
    for(int i=0;i<m;i++){
        if(s1[i]==s2[i]){
            dp[0][i+1]=dp[0][i];
        }
        else{
            dp[0][i+1]=dp[0][i]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==s2[i+j-1]){
                dp[i][j]=min(dp[i-1][j],dp[i][j]);
            }
            else{
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
            }
            if(s1[j-1]==s2[i+j-1]){
                dp[i][j]=min(dp[i][j-1],dp[i][j]);
            }
            else{
                dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
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