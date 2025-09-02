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
bool cmp(const pair<pair<int,int>,int>& a, const pair<pair<int,int>,int>& b) {
    if (a.ff.ff != b.ff.ff)
        return a.ff.ff < b.ff.ff;
    return a.ff.ss > b.ff.ss;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].ff.ff>>v[i].ff.ss;
        v[i].ss=i+1;
    }
    sort(all(v),cmp);
    int a=v[0].ff.ff,b=v[0].ff.ss,c=v[0].ss;
    for(int i=1;i<n;i++){
        if(b>=v[i].ff.ss){
            cout<<v[i].ss<<" "<<c<<endl;
            return;
        }
        else{
            b=v[i].ff.ss;
            c=v[i].ss;
        }
    }
    cout<<-1<<" "<<-1<<endl;
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