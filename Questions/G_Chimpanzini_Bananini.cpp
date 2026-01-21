#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < a.size(); ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
    for (int i = 0; i < a.size(); ++i) \
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
#define mod 998244353
using namespace std;
using namespace __gnu_pbds;
typedef tree < pair < int, int > , null_type, less < pair < int, int >> , rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < int, null_type, less < int > , rb_tree_tag, tree_order_statistics_node_update > ordered_set;

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
    int q;
    cin>>q;
    deque<int> dq;
    int s=0,s1=0,sum=0;
    bool rev=false;
    while(q--){
        int x;
        cin>>x;
        if(x==3){
            int k;
            cin>>k;
            sum+=k;
            if(!rev){
                dq.push_back(k);
                s+=k*dq.size();
                s1+=sum;
                cout<<s<<endl;
            }
            else{
                dq.push_front(k);
                s+=sum;
                s1+=k*dq.size();
                cout<<s1<<endl;
            }
        }
        if(x==2){
            rev=!rev;
            if(!rev){
                cout<<s<<endl;
            }
            else{
                cout<<s1<<endl;
            }
        }
        if(x==1){
            if(!rev){
                int k=dq.back();
                dq.pop_back();
                dq.push_front(k);
                s=s+sum-k*dq.size();
                s1=s1+k*dq.size()-sum;
                cout<<s<<endl;
            }
            else{
                int k=dq.front();
                dq.pop_front();
                dq.push_back(k);
                s1=s1+sum-k*dq.size();
                s=s+k*dq.size()-sum;
                cout<<s1<<endl;
            }
        }
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