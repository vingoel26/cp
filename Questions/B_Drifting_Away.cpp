#include <bits/stdc++.h>
// #define int long long
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
int dp1(vi &dp, int i, string s, int n)
{

    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (s[i - 1] == '>')
    {
        if (i == n)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 1 + dp1(dp, i + 1, s, n);
        }
    }
    else if (s[i - 1] == '<')
    {
        if (i == 1)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = 1 + dp1(dp, i - 1, s, n);
        }
    }
    else
    {
        int left, right;
        if (i == 1)
        {
            left = 0;
        }
        else
        {
            left = dp1(dp, i - 1, s, n);
        }
        if (i == n)
        {
            right = 0;
        }
        else
        {
            right = dp1(dp, i + 1, s, n);
        }
        dp[i] = 1 + max(left, right);
    }
    return dp[i];
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int left = 0, right = n+1, as = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '*' and s[i + 1] == '*')
        {
            cout << -1 << endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='>'){
            right=i+1;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='<'){
            left=i+1;
            break;
        }
    }
    // if(right<left){
    //     cout<<-1<<endl;
    //     return;
    // }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '*' and s[i + 1] == '<')
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '>' and s[i + 1] == '*')
        {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '>' and s[i + 1] == '<')
        {
            cout << -1 << endl;
            return;
        }
    }
    cout<<max(right-1,n-left)<<endl;

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