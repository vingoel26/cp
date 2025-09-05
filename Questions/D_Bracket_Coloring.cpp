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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ct(n + 1);
    for (int j = 0; j < n; j++)
        if (s[j] == '(')
        {
            ct[j + 1] = ct[j] + 1;
        }
        else
        {
            ct[j + 1] = ct[j] - 1;
        }

    if (ct[n] != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        if (*min_element(all(ct)) == 0 or *max_element(all(ct)) == 0)
        {
            cout << 1 << endl;
            for (int j = 0; j < n; j++)
            {
                cout <<1<<" ";
            }
            cout << endl;
        }
        else
        {
            cout << 2 << endl;
            vector<int> ans;
            int i = 0;
            while (i < n)
            {
                int w=2;
                if(s[i]=='('){
                    w=1;
                }
                if(ct[i]==0){
                    i++;
                    ans.push_back(w);
                }
                while (ct[i] != 0)
                {
                    i++;
                    ans.push_back(w);
                }
            }
            for (int j = 0; j < n; j++)
            {
                cout << ans[j]<<" ";
            }
            cout << endl;
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