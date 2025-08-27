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
    set<int> a = {4, 8, 15, 16, 23, 42};
    vi ans(6);
    cout << "? " << 1<< " " << 2 << endl;
    cout.flush();
    int k1;
    cin>>k1;
    cout << "? " << 2<< " " << 3 << endl;
    cout.flush();
    int k2;
    cin>>k2;
    for(auto it : a){
        if((k1*k2)%(it*it)==0 and a.find(k1/it)!=a.end() and a.find(k2/it)!=a.end() and k1/it!=it and k2/it!=it){
            ans[1]=it;
            a.erase(it);
            break;
        }
    }
    ans[0]=k1/ans[1];
    ans[2]=k2/ans[1];
    a.erase(k1/ans[1]);
    a.erase(k2/ans[1]);
    cout << "? " << 4<< " " << 5 << endl;
    cout.flush();
    int k3;
    cin>>k3;
    cout << "? " << 5<< " " << 6 << endl;
    cout.flush();
    int k4;
    cin>>k4;
    for(auto it: a){
        if((k4*k3)%(it*it)==0 and a.find(k3/it)!=a.end() and a.find(k4/it)!=a.end() and k3/it!=it and k4/it!=it){
            ans[4]=it;
            a.erase(it);
            break;
        }
    }
    ans[3]=k3/ans[4];
    ans[5]=k4/ans[4];
    cout<<"!";
    for(int i=0;i<6;i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
    cout.flush();
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