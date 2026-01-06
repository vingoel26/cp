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
#define mod 1000000007
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
    vi a(n);
    vin(a);
    map<int,vi> mp;
    for(int i=0;i<n;i++){
        mp[a[i]].pb(i);
    }
    int ans=-1,ans1=-1;
    for(auto it:mp){
        int mx=1,mx1=1;
        vi v=it.ss;
        for(int i=1;i<v.size();i++){
            mx1=max(1LL,mx1+1-(v[i]-v[i-1]-1));
            mx=max(mx,mx1);
        }
        if(ans1<mx){
            ans1=mx;
            ans=it.ff;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==ans)
            a[i]=1;
        else
            a[i]=-1;
    }
    int mx=-1,mx1=0,l=0,r=0,s=0;
    for(int i=0;i<n;i++){
        mx1+=a[i];
        if(mx<mx1){
            mx=mx1;
            l=s;
            r=i;
        }
        if(mx1<0){
            mx1=0;
            s=i+1;
        }
    }
    cout<<ans<<" "<<l+1<<" "<<r+1<<endl;
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