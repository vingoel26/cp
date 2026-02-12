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
    int n,k;
    cin>>n>>k;
    vector<string> s(k);
    for(int i=0;i<k;i++){
        cin>>s[i];
    }
    viv ct(n,vi(26,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            ct[j][s[i][j]-'a']=1;
        }
    }
    for(int i=1;i<=n;i++){
        if((n%i)==0){
            bool q=true;
            string t(i,'a');
            for(int j=0;j<i;j++){
                bool pos=false;
                for(int k1=0;k1<26;k1++){
                    bool fnd=true;
                    for(int it=j;it<n;it+=i){
                        if(ct[it][k1]==0){
                            fnd=false;
                            break;
                        }
                    }
                    if(fnd){
                        t[j]=char('a'+k1);
                        pos=true;
                        break;
                    }
                }
                if(!pos){
                    q=false;
                    break;
                }
            }
            if(q){
                string ans;
                for(int j=0;j<n/i;j++){
                    ans+=t;
                }
                cout<<ans<<endl;
                break;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}