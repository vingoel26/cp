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
    int n;
    cin>>n;
    set<int> s1,s2;
    int ans=0,ans1=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(s1.count(a)==1 or s2.count(b)==1){
            ans+=c;
            s1.insert(b);
            s2.insert(a);
        }
        else{
            s1.insert(a);
            s2.insert(b);
        }
        ans1+=c;
        // for(auto it : s1){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it : s2){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
    }
    cout<<min(ans,ans1-ans);
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