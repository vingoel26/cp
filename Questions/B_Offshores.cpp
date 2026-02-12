#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < a.size(); ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vi vector<int>
using namespace std;

void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    vi a(n);
    vin(a);
    vi trs(n);
    int s=0;
    for(int i=0;i<n;i++){
        trs[i]=a[i]/x;
        s+=trs[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,a[i]+(s-trs[i])*y);
    }
    cout<<ans<<endl;
}

int32_t main()
{


    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}