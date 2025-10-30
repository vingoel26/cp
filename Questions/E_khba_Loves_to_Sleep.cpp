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

vi fact(200001);

int binExpo(int a, int b, int m){
    if(b == 0) return 1;
    if(b % 2 == 0){
        int res = binExpo(a, b/2, m);
        return (res * res) % m;
    } else {
        return (a * binExpo(a, b-1, m)) % m;
    }
}

int nCr(int n, int r){
    if(r > n) return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod-2, mod)) % mod;
    res = (res * binExpo(fact[n-r], mod-2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

void solve()
{
    int n,k,x;
    cin>>n>>k>>x;
    vi a(n),ans;
    vin(a);
    sort(all(a));
    int l=1,r=x;
    while(l<=r){
        int mid=(l+r)/2;
        vi p;
        int l2=a[0]-mid;
        int l1=0;
        while(l1<=l2 and p.size()<k){
            p.pb(l1++);
        }
        for(int i=0;i<n;i++){
            if(p.size()>=k){
                break;
            }
            if(i==n-1){
                int k1=a[i]+mid;
                while(k1<=x and p.size()<k){
                    p.pb(k1);
                    k1++;
                }
            }
            else{
                int st=a[i]+mid;
                int end=a[i+1]-mid;
                while(st<=end and p.size()<k ){
                    p.pb(st);
                    st++;
                }
            }
        }
        if(p.size()==k){
            ans=p;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(ans.size()==0){
        for(int i=0;i<k;i++){
            ans.pb(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    fast
    // Precompute factorials
    // fact[0] = 1;
    // for(int i = 1; i <= 200000; ++i){
    //     fact[i] = (fact[i-1] * i) % mod;
    // }

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}