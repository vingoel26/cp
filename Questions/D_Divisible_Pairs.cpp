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
    int n,x,y;
    cin>>n>>x>>y;
    vi a(n);
    vin(a);
    map<pair<int,int>,int>m1;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        m1[{a[i]%x,a[i]%y}]++;
        s.insert({a[i]%x,a[i]%y});
    }
    int ans=0;
    for(auto it : s){
        // cout<<it.first<<" "<<it.second<<endl;
        if(it.first==0){
            ans+=m1[it]*(m1[it]-1)/2;
            // cout<<ans<<endl;
        }
        else if(x%2==0 && it.first==x/2){
            ans+=m1[it]*(m1[it]-1)/2;
            //  cout<<ans<<endl;
        }
        // else{
        //     ans+=m1[it]*m1[{(x-it.first)%x,it.second}]/2;
        //     //  cout<<ans<<endl;
        // }
    }
    int ans1=0;
    for(auto it : s){
        if(!(it.first==0) and !(x%2==0 && it.first==x/2)){
            ans1+=m1[it]*m1[{(x-it.first)%x,it.second}];
        }
    }
    cout<<ans+ans1/2<<endl;
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