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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    set<int> r, c;
    map<int, int> m1, m2;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            ct++;
        }
        else
        {
            r.insert(ct);
            m1[ct]++;
            ct = 0;
        }
    }
    if (ct != 0)
    {
        r.insert(ct);
        m1[ct]++;
    }
    ct = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            ct++;
        }
        else
        {
            c.insert(ct);
            m2[ct]++;
            ct = 0;
        }
    }
    if (ct != 0)
    {
        c.insert(ct);
        m2[ct]++;
    }

    // for (int i = 0; i < r.size(); i++)
    // {
    //     cout << r[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < c.size(); i++)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    vi r1(n + 1), c1(m + 1);
    for (auto it : m1)
    {
        for (int i = 1; i <= it.first; i++)
        {
            r1[i] += (it.first - i + 1) * it.second;
        }
    }
    for (auto it : m2)
    {
        for (int i = 1; i <= it.first; i++)
        {
            c1[i] += (it.first - i + 1) * it.second;
        }
    }
    // for (int i = 0; i < r1.size(); i++)
    // {
    //     cout << r1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < c1.size(); i++)
    // {
    //     cout << c1[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            if (i * i == k and i <= n and i <= m)
            {
                ans += r1[i] * c1[k / i];
                continue;
            }
            if (i != k / i and i <= n and k / i <= m)
            {
                ans += r1[i] * c1[k / i];
            }
            if (i != k / i and i <= m and k / i <= n)
            {
                ans += r1[k / i] * c1[i];
            }
        }
    }
    cout << ans << endl;
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