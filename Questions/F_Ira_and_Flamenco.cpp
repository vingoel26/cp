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
int modinv(int n){
    return binExpo(n,mod-2,mod);
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    map<int,int> ct;
    for(int i=0;i<n;i++){
        ct[a[i]]++;
    }
    set<int>s1;
    for(int i=0;i<n;i++){
        s1.insert(a[i]);
    }
    n=s1.size();
    set<int> s;
    int ans=0;
    int res=1;
    a.erase(unique(a.begin(), a.end()), a.end());
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        res*= ct[a[i]];
        res%=mod;
        if(s.size()>m){ 
            res*=(modinv( ct[*s.begin()] ));
            s.erase(*s.begin());
            res%=mod;
        }
        if(s.size()==m){
            if((*s.begin()+m ) > *s.rbegin()){
                ans+=res;
                ans%=mod;
            }else {
                s.clear();
                res=1;
            }
        }
    }
    ans%=mod;
    cout<<ans<<endl;
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