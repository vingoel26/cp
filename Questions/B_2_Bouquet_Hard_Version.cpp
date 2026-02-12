#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                         \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cin >> a[i];                   \
    }
#define vout(a)                        \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cout << a[i] << ' ';           \
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
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    map<int, int> ch;
    for (int i = 0; i < n; i++)
    {
        ch[a[i]] += c[i];
    }
    int ans = 0;
    for (auto &it : ch)
    {
        int x = it.first;
        int c_x = it.second;
        if(x==0){
            continue;
        }
        ans = max(ans, min(m / x, c_x) * x);
        if (ch.count(x + 1))
        {
            int c_x1 = ch[x + 1];
            int k1 = min(m / x, c_x);
            int pred = x * k1;
            int coins = m - pred;
            if (coins >= x + 1)
            {
                int k2 = min(coins / (x + 1), c_x1);
                pred += k2 * (x + 1);
                coins = m - pred;
                c_x1 -= k2;
            }
            ans = max(ans, min(m / (x + 1), c_x1) * (x + 1));
            pred += min({coins, c_x1, k1});
            ans = max(ans, pred);
        }
    }
    cout << ans << endl;
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