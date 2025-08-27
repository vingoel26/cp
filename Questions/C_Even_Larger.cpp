#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                  \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a)                 \
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
#define fast                          \
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
    int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        vector<long long> b(n);
        for(int i=0;i<n;i++){
            b[i] = (i %2 == 0 ? a[i] : -a[i]);
        }

        vector<long long> pref(n+1,0);
        for(int i=1;i<=n;i++) pref[i] = pref[i-1] + b[i-1];

        long long ans = 0;
        long long min_pref = 0;
        for(int i=2;i<=n;i++){
            if(pref[i] < min_pref){
                ans += min_pref - pref[i];
                pref[i] = min_pref;
            }
            min_pref = min(min_pref, pref[i-1]);
        }
        cout << ans << "\n";
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