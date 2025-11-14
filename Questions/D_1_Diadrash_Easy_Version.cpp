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
auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.ff == b.ff ? a.ss > b.ss : a.ff < b.ff;
};   
void solve()
{
    int n,q;
    cin>>n>>q;
    vpi a;
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        a.pb({u,v});
    }
    sort(all(a),cmp);
    vpi b;
    for(auto it : a){
        if(b.empty() or it.ss>b[b.size()-1].ss){
            b.pb(it);
        }
    }
    // for(auto it : b){
    //     cout<<it.ff<<" "<<it.ss<<endl;
    // }
    cout<<"? "<<1<<" "<<(n+1)/2<<endl;
    int x;
    cin>>x;
    vpi c;
    int n1=b.size();
    if(x==0){
        for(int i=0;i<n1;i++){
            if(b[i].ss>(n+1)/2){
                c.pb(b[i]);
            }
        }
    }
    else{
        for(int i=0;i<n1;i++){
            if(b[i].ff<=(n+1)/2){
                c.pb(b[i]);
            }
        }
    }
    // for(auto it : c){
    //     cout<<it.ff<<" "<<it.ss<<endl;
    // }
    int ans=0;
    for(int i=0;i<c.size();i++){
        cout<<"? "<<c[i].ff<<" "<<c[i].ss<<endl;
        int x;
        cin>>x;
        ans=max(ans,x);
    }
    cout<<"! "<<ans<<endl;
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