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
    int p=1,ct1=0,ct2=0;
    int n1=n;
    while(n1%2==0){
        ct1++;
        n1/=2;
    }
    while(n1%5==0){
        ct2++;
        n1/=5;
    }
    while(ct1<ct2 and p*2<=m){
        ct1++;
        p*=2;
    }
    // cout<<p<<" ";
    while(ct1>ct2 and p*5<=m){
        ct2++;
        p*=5;
    }
    // cout<<p<<" ";
    while(p*10<=m){
        p*=10;
    }
    // cout<<p<<" ";
    if(p==1){
        cout<<n*m<<endl;
    }
    else{
        cout<<n*((m/p)*p)<<endl;
    }
    
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