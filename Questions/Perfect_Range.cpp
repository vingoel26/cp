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
#define en r()
#define all(x) x.begin(), x.r()
#define rall(x) x.rbegin(), x.rr()
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
    
    vi a(n);
    vi b(n);
    
    vin(a);
    vin(b);
    
    viv dp(n, vi(2, 1));
    dp[0][0] = 1;
    dp[0][1] = 1;
    
    for(int i = 1; i<n; i++) {
        if(a[i] > a[i-1]) {
            dp[i][0] = 1 + dp[i-1][0];
        }
        if(a[i] > b[i-1]) {
            dp[i][0] = max(dp[i][0], 1 + dp[i-1][1]);
        }
        if(b[i] > a[i-1]) {
            dp[i][1] = 1 + dp[i-1][0];
        }
        if(b[i] > b[i-1]) {
            dp[i][1] = max(dp[i][1], 1 + dp[i-1][1]);
        }
    }
    
    int ct = 0;
    
    for(int l = 0; l<n; l++) {
        int l1 = l, r = n - 1;
        int idx = l;
        while(l1 <= r) {
            int mid = l1 + (r - l1)/2;
            if(mid - max(dp[mid][0], dp[mid][1]) + 1 <= l) {
                idx = mid;
                l1 = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ct += (idx - l + 1);
    }
    
    cout<<ct<<endl;
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