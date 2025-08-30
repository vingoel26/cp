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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    viv df(n+1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        df[x].pb(y);
        df[y].pb(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a1,b;
        cin>>a1>>b;
        if(a1==b){
            cout<<a[b-1]<<endl;
            continue;
        }
        vector<bool>vis(n+1);
        queue<int> q;
        q.push(a1);
        vis[a1]=1;
        vis[b]=1;
        int ans=a[b-1];
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans=ans | a[u-1];
            for (int w : df[u]) {
                if (!vis[w]) {
                    vis[w] = 1;
                    q.push(w);
                }
            }
        }
        cout<<ans<<endl;
    }
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