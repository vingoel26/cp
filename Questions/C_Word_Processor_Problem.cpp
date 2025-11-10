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
#define pt(x) cout << x << endl;
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

vi fact(200001);

int binExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int res = binExpo(a, b / 2, m);
        return (res * res) % m;
    }
    else
    {
        return (a * binExpo(a, b - 1, m)) % m;
    }
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod - 2, mod)) % mod;
    res = (res * binExpo(fact[n - r], mod - 2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n, d;
    cin >> n >> d;
    vi a(n);
    vin(a);
    vi pr(n + 1, 0);
    pr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        pr[i] = pr[i - 1] + a[i - 1] + 1;
    }
    
    
        int l = *max_element(all(a));
        int r = 1000000000000000000;
        int ansmx = 0;
        int ansmn = 1000000000000000000;
        int ansmn1 = 1000000000000000000;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int ct = 0;
            int s = 0;
            for (int i = 0; i < n; i++)
            {
                if (s == 0)
                {
                    s += a[i];
                }
                else
                {
                    s += a[i] + 1;
                }
                if (s > m)
                {
                    ct++;
                    s = a[i];
                }
            }
            ct++;
            

            if (ct == d)
            {
                ansmx = max(ansmx, m);
                // ansmn=min(ansmn,m);
            }
            if (ct >= d)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        l = *max_element(all(a));
        r = 1000000000000000000;
        while (l <= r)
        {
            int m = l + (r - l + 1) / 2;
            int ct = 0;
            int s = 0;
            for (int i = 0; i < n; i++)
            {
                if (s == 0)
                {
                    s += a[i];
                }
                else
                {
                    s += a[i] + 1;
                }
                if (s > m)
                {
                    ct++;
                    s = a[i];
                }
            }
            ct++;
            if (ct == d)
            {
                // ansmx=max(ansmx,m);
                ansmn = min(ansmn, m);
            }
            if (ct > d)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (ansmn == ansmn1 or ansmx == 0)
        {
            cout << -1 << " " << -1 << endl;
            return;
        }
        cout << ansmn << " " << ansmx << endl;
    
}

int32_t main()
{
    fast
        // Precompute factorials
        // fact[0] = 1;
        // for(int i = 1; i <= 200000; ++i){
        //     fact[i] = (fact[i-1] * i) % mod;
        // }

        int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}