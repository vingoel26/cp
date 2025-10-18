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
    vi a(n + 1);
    vin(a);
    a[n] = 0;
    int ans = 0;
    int l = n;
    int r = 0;
    int i = -1;
    int j = 0;
    int pr = 0;
    bool ok = true;
    while (j <= n)
    {
        if (a[j] == 0)
        {
            if (ok)
            {
                if (pr > ans)
                {
                    ans = pr;
                    l = i + 1;
                    r = n - j;
                }
            }
            else
            {
                int tpr = pr;
                int ii = i + 1;
                int jj = j - 1;
                while (ii < j)
                {
                    if (abs(a[ii]) == 2)
                        tpr--;
                    if (a[ii] < 0)
                    {
                        ii++;
                        break;
                    }
                    ii++;
                }
                if (tpr > ans)
                {
                    ans = tpr;
                    l = ii;
                    r = n - j;
                }
                tpr = pr;
                while (jj > i)
                {
                    if (abs(a[jj]) == 2)
                        tpr--;
                    if (a[jj] < 0)
                    {
                        jj--;
                        break;
                    }
                    jj--;
                }
                if (tpr > ans)
                {
                    ans = tpr;
                    l = i + 1;
                    r = n - (jj + 1);
                }
            }
            i = j;
            j++;
            pr = 1;
            ok = true;
        }
        else
        {
            if (a[j] == 2 || a[j] == -2)
                pr++;
            if (a[j] < 0)
                ok = !ok;
            j++;
        }
    }
    // cout<<ans<<endl;
    cout << l << " " << r << endl;
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