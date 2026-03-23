#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #define int long long
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
#define endl "\n"
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
// vi hsh(1e6+5);
vi freq(1e6+5);
void solve()
{
    //xor hash
    // int n,q;
    // cin>>n>>q;
    // vi a(n);
    // vin(a);
    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // for(int i=0;i<n;i++){
    //     hsh[a[i]]=rng();
    // }
    // vi pr(n+1);
    // for(int i=1;i<=n;i++){
    //     pr[i]=(pr[i-1]^hsh[a[i-1]]);
    // }
    // while(q--){
    //     int l,r;
    //     cin>>l>>r;
    //     if(pr[l-1]==pr[r]){
    //         yah
    //     }
    //     else{
    //         nah
    //     }
    // }
    // mo algo
 ;
    int n,q;
    cin>>n>>q;
    vi a(n);
    vin(a);
    vector<pair<pair<int,int>,int>> qw;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        qw.pb({{l,r},i});
    }
    int blk=max(1,(int)(n/sqrt(q)));
    sort(all(qw),[&](pair<pair<int,int>,int>& A, pair<pair<int,int>,int>& B) {
        int block_A = A.ff.ff / blk;
        int block_B = B.ff.ff / blk;
        if (block_A != block_B)
            return block_A < block_B;
        return (block_A % 2 == 1) ? (A.ff.ss < B.ff.ss) : (A.ff.ss > B.ff.ss);
    });
    vi ans(q);
    int ct=0;
    int l=0,r=-1;
    for(auto qw1:qw){
        int l1=qw1.ff.ff;
        int r1=qw1.ff.ss;
        int idx=qw1.ss;
        while(l>l1){
            l--;
            freq[a[l]]++;
            if(freq[a[l]]%2==1){
                ct++;
            }
            else{
                ct--;
            }
        }
        while(r<r1){
            r++;
            freq[a[r]]++;
            if(freq[a[r]]%2==1){
                ct++;
            }
            else{
                ct--;
            }
        }
        while(l<l1){
            freq[a[l]]--;
            if(freq[a[l]]%2==1){
                ct++;
            }
            else{
                ct--;
            }
            l++;
        }
        while(r>r1){
            freq[a[r]]--;
            if(freq[a[r]]%2==1){
                ct++;
            }
            else{
                ct--;
            }
            r--;
        }
        ans[idx]=ct;
    }
    for(int i=0;i<q;i++){
        if(!ans[i]){
            yah
        }
        else{
            nah
        }
    }
    for (int i = 0; i < n; i++) {
        freq[a[i]] = 0; 
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