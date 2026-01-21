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
// #define mod 1000000007
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
    int n, q;
    cin >> n >> q;

    vi a(n), b(n);
    vin(a);
    vin(b);

    vpi a1, b1;
    for (int i = 0; i < n; i++)
    {
        a1.pb({a[i], i});
        b1.pb({b[i], i});
    }

    sort(all(a1));
    sort(all(b1));
    sort(all(a));
    sort(all(b));

    map<int, int> posa1, posb1;
    map<int, int> posa, posb;

    for (int i = 0; i < n; i++)
    {
        posa1[a1[i].ss] = i;
        posb1[b1[i].ss] = i;
        posa[i] = a1[i].ss;
        posb[i] = b1[i].ss;
    }

    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod = (prod * min(a[i], b[i])) % mod;
    }

    cout << prod << " ";

    while (q--)
    {
        int type, idx;
        cin >> type >> idx;
        idx--;

        int v = idx;

        if (type == 1)
        {
            int x = upper_bound(all(a), a[posa1[idx]]) - a.begin() - 1;

            int tmp = posa1[v];
            posa1[v] = x;
            posa1[posa[x]] = tmp;
            posa[tmp] = posa[x];
            posa[x] = v;

            if (a[x] < b[x])
            {
                prod = (prod * binExpo(min(a[x], b[x]), mod - 2, mod)) % mod;
                a[x]++;
                prod = (prod * min(a[x], b[x])) % mod;
            }
            else
            {
                a[x]++;
            }
        }
        else
        {
            int x = upper_bound(all(b), b[posb1[idx]]) - b.begin() - 1;

            int tmp = posb1[v];
            posb1[v] = x;
            posb1[posb[x]] = tmp;
            posb[tmp] = posb[x];
            posb[x] = v;

            if (b[x] < a[x])
            {
                prod = (prod * binExpo(min(a[x], b[x]), mod - 2, mod)) % mod;
                b[x]++;
                prod = (prod * min(a[x], b[x])) % mod;
            }
            else
            {
                b[x]++;
            }
        }

        cout << prod << " ";
    }

    cout << "\n";
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