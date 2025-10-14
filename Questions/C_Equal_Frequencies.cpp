#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
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
#define fast \
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

int binExpo(int a, int b, int m){
    if(b == 0) return 1;
    if(b % 2 == 0){
        int res = binExpo(a, b/2, m);
        return (res * res) % m;
    } else {
        return (a * binExpo(a, b-1, m)) % m;
    }
}

int nCr(int n, int r){
    if(r > n) return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod-2, mod)) % mod;
    res = (res * binExpo(fact[n-r], mod-2, mod)) % mod;
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    viv c(26);
    for (int i = 0; i < n; i++) {
      c[(int) (s[i] - 'a')].pb(i);
    }
    vector<int> a(26);
    iota(all(a), 0);
    sort(all(a), [&](int i, int j) {
      return c[i].size() > c[j].size();
    });
    string res = "";
    int ans = -1;
    for (int k = 1; k <= 26; k++) {
      if (n % k == 0) {
        int cur = 0;
        for (int i = 0; i < k; i++) {
          cur += min(n / k, (int) c[a[i]].size());
        }
        if (cur > ans) {
          ans = cur;
          res = string(n, ' ');
          vector<char> b;
          for (int it = 0; it < k; it++) {
            int i = a[it];
            for (int j = 0; j < n / k; j++) {
              if (j < (int) c[i].size()) {
                res[c[i][j]] = (char) ('a' + i);
              } else {
                b.pb((char) ('a' + i));
              }
            }
          }
          for (char& c : res) {
            if (c == ' ') {
              c = b.back();
              b.pop_back();
            }
          }
        }
      }
    }
    cout << n - ans << '\n';
    cout << res << '\n';
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