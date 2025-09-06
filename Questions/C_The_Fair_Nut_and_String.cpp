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
    string s;
    cin >> s;
    string s1 = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' or s[i] == 'b')
        {
            s1.pb(s[i]);
        }
    }
    // cout<<s1<<endl;
    vi p;
    int ct = 2;
    for (int i = 1; i < s1.size(); i++)
    {
        if (s1[i] == s1[i - 1] and s1[i]=='a')
        {
            ct++;
        }
        else
        {
            if (s1[i - 1] == 'a')
            {
                // cout<<ct<<" ";
                p.pb(ct);
                ct = 2;
            }
        }
        
    }
    // cout<<endl;
    if (s1[s1.size() - 1] == 'a')
    {
        p.pb(ct);
    }
    // for(int i=0;i<p.size();i++){
    //     cout<<p[i]<<" ";
    // }
    // cout<<endl;
    int ans=1;
    for(int i=0;i<p.size();i++){
        ans=(ans*p[i])%mod;
    }
    cout<<ans-1<<endl;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}