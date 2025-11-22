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
#define pt(x) cout << x << endl;
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

vi fact(200001);

int binExpo(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        int res = binExpo(a, b / 2, m);
        return (res * res) % m;
    }
    else
    {
        return (a * binExpo(a, b - 1, m)) % m;
    }
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int res = fact[n];
    res = (res * binExpo(fact[r], mod - 2, mod)) % mod;
    res = (res * binExpo(fact[n - r], mod - 2, mod)) % mod;
    return res;
}

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n)
{

    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {

            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            res.push_back(p);
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vi a,b,c;
    for(int i=1;i<=n;++i){
        if(i%2==0) a.pb(i);
        else if(i%3==0) b.pb(i);
        else c.pb(i);
    }
    while(a.size()>=2 and c.size()>=1){
        cout<<c.back()<<" ";
        c.pop_back();
        cout<<a.back()<<" ";
        a.pop_back();
        cout<<a.back()<<" ";
        a.pop_back();
    }
    while(b.size()>=2 and c.size()>=1){
        cout<<c.back()<<" ";
        c.pop_back();
        cout<<b.back()<<" ";
        b.pop_back();
        cout<<b.back()<<" ";
        b.pop_back();
    }
    while(!a.empty()){
        cout<<a.back()<<" ";
        a.pop_back();
    }
    while(!b.empty()){
        cout<<b.back()<<" ";
        b.pop_back();
    }
    while(!c.empty()){
        cout<<c.back()<<" ";
        c.pop_back();
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