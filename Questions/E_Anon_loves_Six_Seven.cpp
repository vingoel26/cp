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
    string s;
    cin >> s;
    int n = s.length();
    int l, r;
    cin >> l >> r;
    string d = s + s;
    int m = 2 * n;
    vector<int> pr(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (i + 7 < m)
        {
            string word = "";
            for (int j = 0; j < 8; j++)
            {
                word.push_back(d[i + j]);
            }
            if (word == "sixseven")
            {
                pr[i]++;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        pr[i] += pr[i - 1];
    }
    vector<int> rot(n, 0);
    for (int i = 0; i < n; i++)
    {
        int st = i, e = n + i - 8;
        int ct = 0;
        if (e >= 0 and e < m)
            ct += pr[e];
        if (st - 1 >= 0 and st - 1 < m)
            ct -= pr[st - 1];

        rot[i] = ct;
    }
    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        int rhs = (r - i);
        if (rhs >= 0)
        {
            int t = rhs / n + 1;
            ans1 += rot[i] * t;
        }
    }
    int ans2=0;
    for (int i = 0; i < n; i++)
    {
        int rhs = (l-1 - i);
        if (rhs >= 0)
        {
            int t = rhs / n + 1;
            ans2 += rot[i] * t;
        }
    }
    int ans=0;
    if(l>0){
        ans=ans1-ans2;
    }
    else{
        ans=ans1;
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