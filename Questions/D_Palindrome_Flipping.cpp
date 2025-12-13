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

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vpi a,b;
    int p=-1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            p=i;
        }
    }
    if(p==-1){
        if(s[0]=='0' and s[1]=='1' and s[2]=='0'){
            a.pb({1,3});
            s[0]='1';
            s[2]='1';
            s[1]='0';
            p=2;
        }
        else{
            a.pb({1,3});
            s[1]='1';
            s[2]='0';
            s[0]='0';
            p=2;
        }
    }
    char k=s[p+1];
    int l=p,r=p+1;
    while(r+1<n){
        if(s[r+1]!=k){
            a.pb({l+1,r+1});
        }
        k=s[r+1];
        r++;
    }
    while(l>0){
        if(s[l-1]!=k){
            a.pb({l+1,r+1});
        }
        k=s[l-1];
        l--;
    }
    if(k=='1'){
        a.pb({1,n});
    }
    p=-1;
    for(int i=0;i<n-1;i++){
        if(t[i]==t[i+1]){
            p=i;
        }
    }
    if(p==-1){
        if(t[0]=='0' and t[1]=='1' and t[2]=='0'){
            b.pb({1,3});
            t[0]='1';
            t[2]='1';
            t[1]='0';
            p=2;
        }
        else{
            b.pb({1,3});
            t[1]='1';
            t[2]='0';
            t[0]='0';
            p=2;
        }
    }
    k=t[p+1];
    l=p,r=p+1;
    while(r+1<n){
        if(t[r+1]!=k){
            b.pb({l+1,r+1});
        }
        k=t[r+1];
        r++;
    }
    while(l>0){
        if(t[l-1]!=k){
            b.pb({l+1,r+1});
        }
        k=t[l-1];
        l--;
    }
    if(k=='1'){
        b.pb({1,n});
    }
    cout<<a.size()+b.size()<<endl;
    reverse(all(b));
    for(auto x:a){
        cout<<x.ff<<" "<<x.ss<<endl;
    }
    for(auto x:b){
        cout<<x.ff<<" "<<x.ss<<endl;
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