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
    int q;
    cin >> q;
    int a = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            a++;
        }
        if (s[i] == '-')
        {
            m++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int q, w;
        cin >> q >> w;
        if (w > q)
        {
            swap(q, w);
        }
        if (a == m)
        {
            yah continue;
        }
        if(w==q){
            if(a!=m){
                nah
                continue;
            }
        }
        if(a>m){
            swap(a,m);
        }
        int l = 0, r = a;
        while (l < r)
        {
            int m1 = (l + r) / 2;
            int s = m1 * q + (a - m1) * w;
            int s1 = m * w;
            if (s > s1)
            {
                r = m1 - 1;
            }
            else if (s == s1)
            {
                break;
            }
            else
            {
                l = m1 + 1;
            }
        }
        int m1 = (l + r) / 2;
        int s = m1 * q + (a - m1) * w;
        int s1 = m * w;
        if (s==s1){
            yah
        }
        else{
            nah
        }
    }
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