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
    vpi v(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v[i]={l,r};
    }
    int l=-1,r=1e9;
    bool q1=true;
    while(l+1<r){
        int m=(l+r)/2;
        int l1=0,r1=0;
        bool q=false;
        for(int i=0;i<n;i++){
            l1=max(l1-m,v[i].first);
            r1=min(r1+m,v[i].second);
            if(l1>r1){
                l=m;
                q=true;
                break;
            }
        }
        if(!q){
            r=m;
        }
        // if(l>r){
        //     r=m;
        // }
        // cout<<m;
    }
    cout<<r<<endl;
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