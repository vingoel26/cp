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
#define vout(a)                             \
    for (int i = 0; i < (int)a.size(); ++i) \
    {                                       \
        cout << a[i] << ' ';                \
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
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1, 0), lst(n + 1, 0), ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        b[a[i]] = max(b[a[i]], i - lst[a[i]]);
        lst[a[i]] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        b[j] = max(b[j], n - lst[j] + 1);
        for (int i = b[j]; i <= n; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = j;
            }
            else{
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    fast
        inp(t);
    while (t--)
    {
        solve();
    }
    return 0;
}
