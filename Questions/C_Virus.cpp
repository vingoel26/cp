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
    int n, m;
    cin >> n >> m;
    vi a(m);
    vi v, ans;
    v.push_back(1);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    for (int i = 0; i < m; i++)
    {
        v.push_back(a[i]);
    }
    v.push_back(n);
    for (int i = 1; i < v.size(); i++)
    {
        if (i == v.size() - 1)
        {
            ans[0] += v[i] - v[i - 1] + 1;
            break;
        }
        ans.push_back(v[i] - v[i - 1] - 1);
    }
    sort(ans.begin(), ans.end());
    int a1 = 4;
    if (ans.size() > 1)
    {
        for (int i = ans.size() - 2; i >= 0; i--)
        {
            ans[i] -= a1;
            a1 += 4;
        }
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 1)
        {
            sum++;
            continue;
        }
        sum += max(0ll, ans[i] - 1);
    }
    cout << n - sum << endl;
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