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
#define pt(x) cout<<x<<endl;
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
vector<int> printDivisors(int n) {
    vector<int>divisors;
    
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            
            // If divisors are equal, print only one
            if (n / i == i) {
                divisors.push_back(i) ;
            }
            // Otherwise print both 
            else {
                divisors.push_back(i) ;
                divisors.push_back(n/i) ;
            }
        }
    }
    
    return divisors;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    vin(a);
    sort(all(a));
    int l=0,r=0;
    vi b(m+1,0);
    int ct=0,ans=LLONG_MAX;
    for(r=0;r<n;r++){
        vi div=printDivisors(a[r]);
        sort(all(div));
        for(auto x:div){
            if(x<=m){
                if(b[x]==0){
                    ct++;
                }
                b[x]++;
            }
            else{
                break;
            }
        }
        while(ct==m and l<=r){
            ans=min(ans,a[r]-a[l]);
            vi div=printDivisors(a[l]);
            sort(all(div));
            for(auto x:div){
                if(x<=m){
                    b[x]--;
                    if(b[x]==0){
                        ct--;
                    }
                }
                else{
                    break;
                }
            }
            l++;
        }
    }
    if(ans==LLONG_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
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