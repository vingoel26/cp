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
    vi a(n);
    vin(a);
    vi pr(n+1,0);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]^a[i-1];
    }
    vi zero(n+1,0);
    for(int i=1;i<=n;i++){
        zero[i]=zero[i-1]+(a[i-1]==0);
    }
    map<int,vi> mp,mp1;
    for(int i=1;i<=n;i++){
        if(i&1){
            mp[pr[i]].pb(i);
        }
        else{
            mp1[pr[i]].pb(i);
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(r-l+1==1){
            if(a[l-1]==0){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        if(r-l+1==2){
            if(a[l-1]==0 and a[r-1]==0){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        int ct=zero[r]-zero[l-1];
        if(ct==r-l+1){
            cout<<0<<endl;
            continue;
        }
        if((r-l+1)%2==1){
            int x=pr[r]^pr[l-1];
            if(x==0){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        else{
            int x=pr[r]^pr[l-1];
            if(x!=0){
                cout<<-1<<endl;
                continue;
            }
            bool q=false;
            if(l&1){
                vi &a1=mp[pr[l-1]];
                auto it=lower_bound(all(a1),l);
            if(it!=a1.end() and *it<=r-1){
                q=true;
            }
            if(!q){
                cout<<-1<<endl;
            }
            else{
                if(a[l-1]==0 or a[r-1]==0){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            }
            else{
                vi &a1=mp1[pr[l-1]];
                auto it=lower_bound(all(a1),l);
            if(it!=a1.end() and *it<=r-1){
                q=true;
            }
            if(!q){
                cout<<-1<<endl;
            }
            else{
                if(a[l-1]==0 or a[r-1]==0){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            }
            
        }
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}