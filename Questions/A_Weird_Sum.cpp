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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    map<int,vector<int>> m1,m2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            m1[v[i][j]].pb(i+1);
            m2[v[i][j]].pb(j+1);
        }
    }
    for(auto &it : m1){
        sort(rall(it.second));
    }
    for(auto &it : m2){
        sort(rall(it.second));
    }
    //  for(auto it : m1){
    //     cout<<it.first<<endl;
    //     for(auto it2 : it.second){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(auto it : m2){
    //     cout<<it.first<<endl;
    //     for(auto it2 : it.second){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    for(auto it : m1){
        int k=it.second.size()-1;
        for(auto it2 : it.second){
            ans+=k*(it2);
            k-=2;
        }
    }
    for(auto it : m2){
        int k=it.second.size()-1;
        for(auto it2 : it.second){
            ans+=k*(it2);
            k-=2;
        }
    }
    cout<<ans<<endl;
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