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
    int n,m;
    cin>>n>>m;
    vi a(n);
    vin(a);
    vi b(m);
    vin(b);
    int mx=*max_element(all(b));
    mx=max(mx, *max_element(all(a)));
    int ct1=0,ct2=0,ct3=0;
    int l=a[0];
    bool q=true;
    for(int i=0;i<n;i++){
        l=(l/__gcd(l,a[i]))*a[i];
        if(l>mx){
            q=false;
            break;
        }
    }
    if(q){
        for(int i=0;i<m;i++){
            if(b[i]%l==0){
                ct1++;
            }
        }
    }
    vi vis(mx+1,0);
    for(int i=0;i<n;i++){
        vis[a[i]]=1;
    }
    vi div(mx+1,0);
    for(int i=1;i<=mx;i++){
        if(vis[i] and !div[i]){
            for(int j=i;j<=mx;j+=i){
                div[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(!div[b[i]] and b[i]%l!=0){
            ct2++;
        }
    }
    ct3=m-ct1-ct2;
    if(ct3%2==0){
        if(ct1>ct2){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
    }
    else{
        if(ct1>=ct2){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}