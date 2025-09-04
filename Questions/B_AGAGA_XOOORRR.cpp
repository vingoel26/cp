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
    int x=0;
    map<int,int>m;
    for(int i=0;i<n;i++){
        x=x^a[i];
        m[a[i]]++;
    }
    // cout<<x<<endl;
    if(m.size()==1){
        yah
        return;
    }
    if(x==0){
        yah
    }
    else{
        vi b(n);
        b[0]=a[0];
        for(int i=1;i<n;i++){
            b[i]=a[i]^b[i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int fs=b[i-1];
                int sc=b[j-1]^b[i-1];
                int th=b[n-1]^b[j-1];
                if(fs==sc and sc==th){
                    yah
                    return;
                }
                // cout<<fs<<" "<<sc<<" "<<th<<endl;
            }
        }
        nah
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