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
    int n, m, k;
    cin >> n >> m >> k;
    vi arr(n);
    vin(arr);
    sort(all(arr));
    vector<int> brr(m, 0);
    vin(brr);
    sort(all(brr));
    vector<int> mxl(k + 1, 1e9);
    vector<int> mxr(k + 1, 0);
    string s;
    cin >> s;
    int curr = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'L')
            curr--;
        else
            curr++;
        mxl[i + 1] = min(mxl[i], curr);
        mxr[i + 1] = max(mxr[i], curr);
    }
    vector<int> prel(n, 1e9);
    vector<int> prer(n, 1e9);
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(all(brr), arr[i]) - brr.begin();
        if (idx != m)
        {
            prer[i] = (brr[idx] - arr[i]);
        }
        if (idx)
        {
            prel[i] = (arr[i] - brr[idx - 1]);
        }
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int idx1 = k + 1;
        int idx2 = k + 1;
        if (prel[i] != 1e9)
        {
            int lo = 1;
            int hi = k;
            int tar = -1 * prel[i];
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (mxl[mid] <= tar)
                {
                    idx1 = mid;
                    hi = mid - 1;
                }
                else
                    lo = mid + 1;
            }
        }
        if (prer[i] != 1e9)
        {
            idx2 = lower_bound(all(mxr), prer[i]) - mxr.begin();
        }
        ans[i] = min(idx1, idx2);
    }
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] <= k)
        {
            mpp[ans[i]]++;
        }
    }
    vector<int> pre(k + 2, 0);
    for (auto it : mpp)
    {
        if (it.first >= 1 and it.first <= k)
        {
            pre[it.first] += it.second;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= k; i++)
    {
        cout << max(n - pre[i], 0ll) << ' ';
    }
    cout << endl;
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