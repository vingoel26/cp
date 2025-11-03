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
    vi e,o;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            e.pb(a[i]);
        }
        else{
            o.pb(a[i]);
        }
    }
    sort(all(o));
    int p1=0,p2=0;
    int s=0;
    for(int i=0;i<e.size();i++){
        s+=e[i];
    }
    p1=s/2;
    p2=s/2;
    if(o.size()==0){
        cout<<p1<<" "<<p2<<endl;
        return;
    }
    vpi b;
    int ct=1;
    // for(int i=0;i<o.size();i++){
    //     cout<<o[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<o.size()-1;i++){
        if(o[i]==o[i+1]){
            ct++;
        }
        else{
            b.pb({ct,o[i]});
            ct=1;
        }
    }
    b.pb({ct,o[o.size()-1]});
    sort(rall(b));
    // for(int i=0;i<b.size();i++){
    //     cout<<b[i].ff<<" "<<b[i].ss<<endl;
    // }
    for(int i=0;i<b.size();i++){
        if(i%2==0){
            p1+=b[i].ff*((b[i].ss/2)+1);
            p2+=b[i].ff*((b[i].ss/2));
        }
        else{
            p1+=b[i].ff*((b[i].ss/2));
            p2+=b[i].ff*((b[i].ss/2)+1);
        }
    }
    cout<<p1<<" "<<p2<<endl;
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