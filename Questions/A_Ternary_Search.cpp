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
    int n, x;
    cin >> n >> x;
    vi a(n);
    vin(a);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (a[mid1] == x)
        {
            cout << 0 << endl;
            return;
        }
        if (a[mid2] == x)
        {
            cout << 0 << endl;
            return;
        }
        if (x < a[mid1])
        {
            high = mid1 - 1;
        }
        else if (x > a[mid2])
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    cout<<1<<endl;
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