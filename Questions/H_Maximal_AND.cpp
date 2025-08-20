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
    int n, k;
    cin >> n >> k;
    vi a(n), b(31);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 31; j++)
        {
            if (a[i] & (1LL << j))
            {
                b[j]++;
            }
        }
    }
    int ans=a[0];
    for(int i=1;i<n;i++){
        ans=ans & a[i];
    }
    for(int i=30;i>=0;i--){
        if(n-b[i]<=k){
            ans=ans | (1LL << i);
            k=k-(n-b[i]);
        }
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