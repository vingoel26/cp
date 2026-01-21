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
    vector<vector<string>> ans(100);
    ans[1].pb("1");
    ans[3].pb("169");
    ans[3].pb("196");
    ans[3].pb("961");
    for(int i=5;i<100;i+=2){
        string s=ans[i-2][0];
        string t;
        t.pb('1');
        for(int j=0;j<(i-3)/2;j++){
            t.pb('0');
        }
        t.pb('6');
        for(int j=0;j<(i-3)/2;j++){
            t.pb('0');
        }
        t.pb('9');
        ans[i].pb(t);
        for(int j=0;j<i-2;j++){
            string s1=ans[i-2][j];
            s1.pb('0');
            s1.pb('0');
            ans[i].pb(s1);
        }
        s=ans[i-2][i-3];
        t="";
        t.pb('9');
        for(int j=0;j<(i-3)/2;j++){
            t.pb('0');
        }
        t.pb('6');
        for(int j=0;j<(i-3)/2;j++){
            t.pb('0');
        }
        t.pb('1');
        ans[i].pb(t);
    }
    while (t--)
    {
        int n;
        cin>>n;
        for(auto &it:ans[n]){
            cout<<it<<endl;
        }
        cout<<endl;
    }
    return 0;
}