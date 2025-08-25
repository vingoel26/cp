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
    int a,b,k;
    cin>>a>>b>>k;
    vector<pair<int,int>>v(k);
    for(int i=0;i<k;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<k;i++){
        cin>>v[i].second;
    }
    map<int,int>m1,m2;
    for(int i=0;i<k;i++){
        m1[v[i].first]++;
        m2[v[i].second]++;
    }
    int ans=0;
    for(auto it : v){
        ans+=k-m1[it.first]-m2[it.second]+1;
    }
    cout<<ans/2<<endl;
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