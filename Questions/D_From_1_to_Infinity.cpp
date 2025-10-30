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

void solve(int t)
{
    int n;
    cin>>n;
    // if(t==20000-193){
    //     cout<<n<<endl;
    // }
    int ct=9,ln=1;
    while(n-ct*ln>0){
        n=n-ct*ln;
        ct=ct*10;
        ln++;
    }
    int n1=ct/9+(n-1)/ln;
    int ans=0;
    // int n2=n1;
    // while(n2>0){
    //     ans+=n2%10;
    //     n2=n2/10;
    // }
    string s=to_string(n1);
    for(int i=0;i<=(n-1)%ln;i++){
        ans+=s[i]-'0';
    }
    int s1=0;
    for(int i=0;i<s.length();i++){
        int d=s[i]-'0';
        if(d!=0){
            int k=d*(ln-1)*ct/2;
            int k1=d*(2*s1+d-1)/2*ct/9;
            ans+=k1+k;
        }
        ct/=10;
        ln--;
        s1+=d;
    }
    cout<<ans<<endl;
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
        solve(t);
    }
    return 0;
}