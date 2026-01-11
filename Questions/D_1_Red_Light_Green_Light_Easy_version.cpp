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
void query(int n,int k, vi &p, vi &d){
    int dir=1;
        viv vis(n,vi(2,0));
        int pst;
        cin>>pst;
        int t=0;
        while(true){
            int id=-1;
            if(dir==1){
                id=lower_bound(all(p),pst)-p.begin();
                if(id==n){
                    yah
                    return;
                }
            }
            else{
                id=upper_bound(all(p),pst)-p.begin()-1;
                if(id<0){
                    yah
                    return;
                }
            }
            int d1=abs(pst-p[id]);
            t+=d1;
            pst=p[id];
            if(((t-d[id])%k+k)%k==0){
                if(dir==1){
                    if(vis[id][0]==1){
                        nah
                        return;
                    }
                    vis[id][0]=1;
                    dir=-1;
                }
                else{
                    if(vis[id][1]==1){
                        nah
                        return;
                    }
                    vis[id][1]=1;
                    dir=1;
                }
            }
            pst+=dir;
            t++;
        }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vi p(n),d(n);
    vin(p);
    vin(d);
    int q;
    cin>>q;
    while(q--){
        query(n,k,p,d);
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