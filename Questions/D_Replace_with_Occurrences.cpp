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
    cin>>n;
    vi a(n);
    vi ans(n);
    map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].pb(i);
        // b[i].first=a[i];
        // b[i].second=i;
    }
    for(auto it : m){
        if(it.second.size()%it.first!=0){
            cout<<-1<<endl;
            return;
        }
    }
    int k=1;
    for(auto it : m){
        int ct=0;
        for(int i=0;i<it.second.size();i++){
            if(ct==it.first){
                ct=0;
                k++;
            }
            ans[it.second[i]]=k;
            ct++;
        }
        k++;
    }
    vout(ans);
    cout<<endl;
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