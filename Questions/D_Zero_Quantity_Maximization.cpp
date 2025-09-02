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
    cin >> n;
    vector<int> a(n), b(n);
    vin(a);
    vin(b);
    map<pair<int,int>,int>m;
    for(int i=0;i<n;i++){
        if (a[i] != 0) {
            int a1 = -b[i];
            int a2 = a[i];
            int g = __gcd(a1, a2);
            a1 /= g;
            a2 /= g;
            if (a2 < 0) {
            a1 = -a1;
            a2 = -a2;
            }
            m[{a1, a2}]++;
        }
    }
    int ans=0;
    for(auto it :m){
        ans=max(ans,it.second);
    }
    for(int i=0;i<n;i++){
        if (a[i] == 0) {
            if(b[i]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}