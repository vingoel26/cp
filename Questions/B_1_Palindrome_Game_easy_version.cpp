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
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    int ans = 1e9;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int i = 0;
        int j = n - 1;
        int ct = 0;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else if (s[i] == it->first)
            {
                ct++;
                i++;
            }
            else if (s[j] == it->first)
            {
                ct++;
                j--;
            }
            else
            {
                ct = 1e9;
                break;
            }
        }
        ans = min(ans, ct);
    }
    if (ans == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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