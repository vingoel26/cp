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
bool ispalindrom(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (ispalindrom(s))
    {
        int c = 0;
        char a;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                c++;
            }
            if (i == n / 2)
            {
                a = s[i];
            }
        }
        if (c == n)
        {
            cout << "DRAW" << endl;
        }
        else
        {
            if (n - c == 1)
            {
                cout << "BOB" << endl;
            }
            else
            {
                if (n % 2 && a == '0')
                {
                    cout << "ALICE" << endl;
                }
                else
                {
                    cout << "BOB" << endl;
                }
            }
        }
    }
    else{
        int ct=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ct++;
            }
        }
        if(ct==2 and s[n/2]=='0' and n%2==1){
            cout << "DRAW" << endl;
        }
        else{
            cout << "ALICE" << endl;
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