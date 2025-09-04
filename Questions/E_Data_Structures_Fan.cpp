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
    vin(a);
    string s;
    cin>>s;
    int o=0,z=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            o=o^a[i];
        }
        else{
            z=z^a[i];
        }
    }
    vi pr(n+1);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]^a[i-1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int s;
        cin>>s;
        if(s==2){
            int a;
            cin>>a;
            if(a==0){
                cout<<z<<" ";
            }
            else{
                cout<<o<<" ";
            }
        }
        else{
            int l,r;
            cin>>l>>r;
            z=z^(pr[l-1]^pr[r]);
            o=o^(pr[l-1]^pr[r]);
        }
    }
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