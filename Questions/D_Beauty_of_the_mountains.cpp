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
    int n,m,k;
    cin>>n>>m>>k;
    viv a(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    viv d(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            d[i][j]=(grid[i][j]-'0');
        }
    }
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]==1){
                s+=a[i][j];
            }
            else{
                s-=a[i][j];
            }
        }
    }
    if(s==0){
        yah
        return;
    }
    viv prd(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            prd[i][j]=d[i-1][j-1]+prd[i-1][j]+prd[i][j-1]-prd[i-1][j-1];
        }
    }
    set<int>diff;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            int k1=prd[i][j]-prd[i-k][j]-prd[i][j-k]+prd[i-k][j-k];
            k1=(k*k - k1)-k1;
            diff.insert(abs(k1));
        }
    }
    if(diff.find(0)!=diff.end()){
        diff.erase(0);
    }
    if(diff.size()==0){
        nah
        return;
    }
    int gcd=*diff.begin();
    for(auto it:diff){
        gcd=__gcd(gcd,it);
    }
    if(s%gcd==0){
        yah
    }
    else{
        nah
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