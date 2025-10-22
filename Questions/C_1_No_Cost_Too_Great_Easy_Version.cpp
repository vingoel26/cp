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

// void primeFactors(int n,map<int,int> &ct) {
//     if(n%2==0){
//         ct[2]++;
//         while(n%2==0){
//             n=n/2;
//         }
//     }
//     for(int i=3;i*i<=n;i++){
//         if(n%i==0){
//             ct[i]++;
//             while(n%i==0){
//                 n=n/i;
//             }
//         }
//     }
//     if(n>1){
//         ct[n]++;
//     }
// }
vector<int> primeFactorsvec(int n) {
    vector<int> factors;
    if (n % 2 == 0) {
        factors.push_back(2);
        while(n%2==0){
            n = n / 2;
        }
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while(n%i==0){n = n / i;}
        }
    }
    if (n > 2)
        factors.push_back(n);
    return factors;
}
void solve()
{
    int n;
    cin>>n;
    vi a(n),b(n);
    vin(a);
    vin(b);
    map<int,int> ct;
    viv c;
    for(int i=0;i<n;i++){
        c.pb(primeFactorsvec(a[i]));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c[i].size();j++){
            ct[c[i][j]]++;
        }
    }
    for(auto it : ct){
        if(it.ss>=2){
            cout<<0<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        vi ab=primeFactorsvec(a[i]+1);
        for(int j=0;j<ab.size();j++){
            if(ct.find(ab[j])!=ct.end()){
                if(ct[ab[j]]>=1){
                    bool q=true;
                    for(int k=0;k<c[i].size();k++){
                        if(ab[j]==c[i][k]){
                            q=false;
                            break;
                        }
                    }
                    if(q){
                        cout<<1<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<2<<endl;
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