#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define vppi vector<vector<pair<int,int>>>
#define up upper_bound
#define low lower_bound
#define mod 1000000007
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

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
    int n,q;
    cin>>n>>q;
    vi a(n+1),s(n+1,0),x(n+1,0),nz;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        x[i]=x[i-1]^a[i];
        if(a[i]>0){
            nz.pb(i);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int v=(s[r]-s[l-1])-(x[r]^x[l-1]);
        if(v==0){
            cout<<l<<" "<<l<<endl;
            continue;
        }
        int li=low(all(nz),l)-nz.begin();
        int ri=up(all(nz),r)-nz.begin()-1;
        int bl=l,br=r;
        int blen=r-l+1;
        int lim=min(ri,li+31);
        for(int i=li;i<=lim;++i){
            int ll=nz[i];
            int lo=i,hi=ri,ar=-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                int rr=nz[mid];
                int cf=(s[rr]-s[ll-1])-(x[rr]^x[ll-1]);
                if(cf==v){
                    ar=rr;
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            if(ar!=-1 and ar-ll+1<blen){
                blen=ar-ll+1;
                bl=ll;
                br=ar;
            }
        }
        cout<<bl<<" "<<br<<endl;
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