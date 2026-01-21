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

bool can_cost_4(int L, int W, int R, int G, int B) {
    int sides[4] = {L, L, W, W};
    int colors[3] = {R, G, B};
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                for (int d = 0; d < 3; d++) {
                    int used[3] = {0, 0, 0};
                    used[a] += sides[0];
                    used[b] += sides[1];
                    used[c] += sides[2];
                    used[d] += sides[3];
                    if (used[0] == colors[0] &&
                        used[1] == colors[1] &&
                        used[2] == colors[2])
                        return true;
                }
    return false;
}
bool can_cost_5(int L, int W, int R, int G, int B) {
    int side[4] = {L, L, W, W};

    for (int split = 0; split < 4; split++) {
        int other[3], idx = 0;
        for (int i = 0; i < 4; i++)
            if (i != split) other[idx++] = i;

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                for (int c = 0; c < 3; c++) {
                    int used[3] = {0, 0, 0};
                    used[a] += side[other[0]];
                    used[b] += side[other[1]];
                    used[c] += side[other[2]];

                    int r2 = R - used[0];
                    int g2 = G - used[1];
                    int b2 = B - used[2];

                    if (r2 < 0 || g2 < 0 || b2 < 0) continue;

                    if (r2 + g2 + b2 != side[split]) continue;

                    int cnt = 0;
                    if (r2 > 0) cnt++;
                    if (g2 > 0) cnt++;
                    if (b2 > 0) cnt++;

                    if (cnt == 2)
                        return true;
                }
    }
    return false;
}

void solve() {
    int L, W, R, G, B;
    cin >> L >> W >> R >> G >> B;
    if (can_cost_4(L, W, R, G, B)) {
        cout << 4 << "\n";
        return;
    }
    int mxSide = max(L, W);
    int mxColor = max({R, G, B});

    if (can_cost_5(L, W, R, G, B)) {
        cout << 5 << "\n";
        return;
    }
    cout << 6 << "\n";
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