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
    int n;
    cin >> n;
    vi v(n);
    vin(v)
    vi ans(n);
    ans[n - 1] = *max_element(all(v));
    vi prmx(n);
    prmx[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prmx[i] = max(prmx[i - 1], v[i]);
    }
    vi suffmn(n);
    suffmn[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffmn[i] = min(suffmn[i + 1], v[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (prmx[i] > suffmn[i + 1])
        {
            ans[i] = ans[i + 1];
        }
        else
        {
            ans[i] = prmx[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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