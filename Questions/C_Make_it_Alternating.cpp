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
#define mod 998244353
using namespace std;

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

int modFact(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}
void solve()
{
    string s;
    cin >> s;
    vector<pair<char, int>> v;
    int n = s.size();
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            c++;
        }
        else
        {
            if (c == 0)
            {
                continue;
            }
            v.push_back({s[i], c + 1});
            c = 0;
        }
    }
    if (c != 0)
    {
        v.push_back({s[n - 1], c + 1});
    }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    // cout << endl;
    int ans = 0, ans1 = 1;
    for(int i=0;i<v.size();i++){
        ans+=v[i].second-1;
    }
    cout<<ans<<" ";
    int o=0,z=0,oc=0,zc=0,zp=1,op=1;
    for(int i=0;i<v.size();i++){
        if(v[i].first=='1'){
            o+=v[i].second-1;
            // oc++;
            op=(op*v[i].second)%mod;
        }
        else{
            z+=v[i].second-1;
            // zc++;
            zp=(zp*v[i].second)%mod;
        }
    }
    ans1=(op*modFact(ans,mod))%mod;
    ans1=(ans1*zp)%mod;
    cout<<ans1<<endl;
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