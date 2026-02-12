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
#define INF 1e18

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

struct SegTree
{
    int size;
    vector<int> tree, lazy;

    int merge(int l, int r) { return min(l, r); }

    void push(int i, int l, int r)
    {
        tree[i] = min(tree[i], lazy[i]);
        if (l != r)
        {
            lazy[2 * i] = min(lazy[2 * i], lazy[i]);
            lazy[2 * i + 1] = min(lazy[2 * i + 1], lazy[i]);
        }
        lazy[i] = INF;
    }

    void upd(int lx, int rx, int val, int i, int l, int r)
    {
        push(i, l, r);
        if (l > rx || r < lx)
        {
            return;
        }
        if (l >= lx && r <= rx)
        {
            tree[i] = min(tree[i], val);
            if (l != r)
            {
                lazy[2 * i] = min(lazy[2 * i], val);
                lazy[2 * i + 1] = min(lazy[2 * i + 1], val);
            }
            return;
        }
        int m = (l + r) / 2;
        upd(lx, rx, val, 2 * i, l, m);
        upd(lx, rx, val, 2 * i + 1, m + 1, r);
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }

    int query(int lx, int rx, int i, int l, int r)
    {
        push(i, l, r);
        if (l > rx || r < lx)
            return INF;
        if (l >= lx && r <= rx)
            return tree[i];
        int m = (l + r) / 2;
        int left = query(lx, rx, 2 * i, l, m);
        int right = query(lx, rx, 2 * i + 1, m + 1, r);
        return merge(left, right);
    }

    SegTree(int n)
    {
        tree.resize(4 * n, INF);
        lazy.resize(4 * n, INF);
        size = n - 1;
    }

    void upd(int lx, int rx, int val) { upd(lx, rx, val, 1, 0, size); }
    int query(int lx, int rx) { return query(lx, rx, 1, 0, size); }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    SegTree st(n);
    st.upd(0, 0, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a2[i];
        a2[i]--;
    }
    int s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        s += a1[i];
        int z = st.query(i, i);
        if (z == INF)
        {
            break;
        }
        ans = max(ans, s - z);
        st.upd(0, a2[i], z + a1[i]);
    }
    cout << ans << '\n';
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