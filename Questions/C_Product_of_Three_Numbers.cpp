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
map<int, int> primeFactors(int n)
{
    map<int, int> m;
    while (n % 2 == 0)
    {
        m[2]++;
        n = n / 2;
    }
    for (int i = 3; i*i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            m[i]++;
            n = n / i;
        }
    }
    if (n > 1)
    {
        m[n]++;
    }
    return m;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> m = primeFactors(n);
    // for(auto it : m){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<endl;
    if (m.size() == 1)
    {
        for (auto it : m)
        {
            if (it.second >= 6)
            {
                yah;
                cout << it.first << " " << it.first * it.first << " " << n/( it.first * it.first*it.first) << endl;
            }
            else
            {
                nah;
            }
        }
    }
    else if (m.size() == 2)
    {
        int c = 0, p = 1;
        for (auto it : m)
        {
            c += it.second;
        }
        if (c > 3)
        {
            yah for (auto it : m)
            {
                p*=it.first;
                cout << it.first << " ";
            }
            cout<<n/p<<endl;
        }
        else{
            nah
        }
    }
    else
    {
        // yah;
        int c = 0, p = 1;
        for (auto it : m)
        {
            // cout << it.first << " ";
            p = p * it.first;
            c++;
            if (c == 2)
            {
                break;
            }
        }
        if (p == n)
        {
            nah
        }
        else
        {
            yah;
            c = 0;
            for (auto it : m)
            {
                cout << it.first << " ";
                // p = p * it.first;
                c++;
                if (c == 2)
                {
                    break;
                }
            }
            cout << n / p << endl;
        }
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