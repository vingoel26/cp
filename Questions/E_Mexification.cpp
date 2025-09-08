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

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi f(n + 1), f1(n + 1);
    int mx = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
        mx = max(mx, a[i]);
        s += a[i];
    }
    int mex = n + 1;
    for (int i = 0; i <= n; i++)
    {
        if (f[i] == 0)
        {
            mex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= mex)
        {
            a[i] = mex;
        }
        else
        {
            if (f[a[i]] > 1)
            {
                a[i] = mex;
            }
        }
    }
    if(k==1){
        cout<<accumulate(all(a),0LL)<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        f1[a[i]]++;
    }
    mex = n + 1;
    for (int i = 0; i <= n; i++)
    {
        if (f1[i] == 0)
        {
            mex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= mex)
        {
            a[i] = mex;
        }
        else
        {
            if (f1[a[i]] > 1)
            {
                a[i] = mex;
            }
        }
    }
    if(k%2==0){
        cout<<accumulate(all(a),0LL)<<endl;
        return;
    }
    vi f2(n+1);
    for(int i=0;i<n;i++){
        f2[a[i]]++;
    }
    mex = n + 1;
    for (int i = 0; i <= n; i++)
    {
        if (f2[i] == 0)
        {
            mex = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= mex)
        {
            a[i] = mex;
        }
        else
        {
            if (f2[a[i]] > 1)
            {
                a[i] = mex;
            }
        }
    }
    cout<<accumulate(all(a),0LL)<<endl;
}

int32_t main()
{
    fast int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}