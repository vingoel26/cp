#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a)                         \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cin >> a[i];                   \
    }
#define vout(a)                        \
    for (int i = 0; i < a.size(); ++i) \
    {                                  \
        cout << a[i] << ' ';           \
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
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

void solve()
{
    int n,k,p,s;
    cin>>n>>k>>p>>s;
    vi v(n),a(n),b,c;
    set<int> st;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]--;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    p--;
    s--;
    while(true)
    {
        if(st.find(p)!=st.end())
        {
            break;
        }
        st.insert(p);
        b.pb(a[p]);
        p=v[p];
        if(p==v[p] or b.size()==n)
        {
            break;
        }
    }
    st.clear();
    while(true)
    {
        if(st.find(s)!=st.end())
        {
            break;
        }
        st.insert(s);
        c.pb(a[s]);
        s=v[s];
        if(s==v[s] or c.size()==n)
        {
            break;
        }
    }
    int pmx=0;
    int smx=0;
    int s1=0;
    int ct=0;
    for(int i=0;i<b.size();i++)
    {
        if(ct==k)
        {
            break;
        }
        ct++;
        s1+=b[i];
        pmx=max(pmx,s1+(k-i-1)*b[i]);
    }
    s1=0;
    ct=0;
    for(int i=0;i<c.size();i++)
    {
        if(ct==k)
        {
            break;
        }
        ct++;
        s1+=c[i];
        smx=max(smx,s1+(k-i-1)*c[i]);
    }
    if(pmx>smx)
    {
        cout<<"Bodya"<<endl;
    }
    else if(smx>pmx)
    {
        cout<<"Sasha"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
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