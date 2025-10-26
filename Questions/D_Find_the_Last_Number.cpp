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

vi fact(200001);

int binExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int x = binExpo(a, b / 2, m);
        return (x * x) % m;
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
    int x = fact[n];
    x = (x * binExpo(fact[r], mod - 2, mod)) % mod;
    x = (x * binExpo(fact[n - r], mod - 2, mod)) % mod;
    return x;
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
    int n;
    cin >> n;
    set<int> a, b;
    for (int i = 1; i < n; i++)
    {
        a.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        b.insert(i);
    }
    int k = 0;
    int n1 = n;
    while (n1)
    {
        k++;
        n1 >>= 1;
    }
    int ans = 0;
    for (int d = 0; d < k; d++)
    {
        set<int> a1, a2;
        set<int> b1, b2;
        for (int it : a)
        {
            cout << "? " << it << " " << (1 << d) << endl;
            int x;
            cin >> x;
            if (x == 0)
            {
                a1.insert(it);
            }
            else
            {
                a2.insert(it);
            }
        }
        int z = 0, o = 0;
        for (int num : b)
        {
            if (num & (1 << d))
            {
                o++;
                b2.insert(num);
            }
            else
            {
                z++;
                b1.insert(num);
            }
        }
        if (z == a1.size())
        {
            ans += (1 << d);
            a = a2;
            b = b2;
        }
        else if (o == a2.size())
        {
            a = a1;
            b = b1;
        }
    }
    cout << "! " << ans << endl;
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