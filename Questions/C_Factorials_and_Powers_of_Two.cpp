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

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n;
    cin>>n;
    int f=6,k=4;
    vi fact;
    while(f<=1000000000009){
        fact.pb(f);
        f=f*k;
        k++;
    }
    vpi v;
    int sz = fact.size();
    for (int mask = 0; mask < (1 << sz); ++mask) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) {
                sum += fact[i];
                cnt++;
            }
        }
        if (sum <= n) {
            v.pb({sum, cnt});
        }
    }
    int ans=1e18;
    for(int i=0;i<v.size();i++){
        ans = min(ans, v[i].second + __builtin_popcountll(n - v[i].first));
        // cout<<v[i].first<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fast int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}