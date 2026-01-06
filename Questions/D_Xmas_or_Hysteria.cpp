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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vin(a);
    vpi b;
    for (int i = 0; i < n; i++)
    {
        b.pb({a[i], i + 1});
    }
    sort(all(b));
    if (2 * m > n)
    {
        cout << -1 << endl;
        return;
    }
    if (m == 0)
    {
        if (n == 2)
        {
            cout << -1 << endl;
            return;
        }
        vpi ans;
        sort(rall(b));
        int x = b[0].ff;
        int s = 0;
        int idx = -1;
        for(int i=1;i<n;i++){
            s+=b[i].ff;
            if(s>=x){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }
        for(int i=idx+1;i<n;i++){
            ans.pb({b[i].ss,b[i-1].ss});
        }
        if(!ans.empty()){
            reverse(all(ans));
        }
        for(int i=idx;i>=1;i--){
            ans.pb({b[i].ss,b[0].ss});
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
        }
    }
    else
    {
        cout << n - m << endl;
        for (int i = 0; i < n - m; i++)
        {
            cout << b[m + i].ss << " " << b[i].ss << endl;
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