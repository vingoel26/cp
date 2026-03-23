#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define vppi vector<vector<pair<int,int>>>
#define up upper_bound
#define low lower_bound
// #define mod 1000000007
#define mod 998244353
#define endl "\n"
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
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}
vector<int> nextSmallerEle(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n); 
    stack<int> st; 
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    vin(a);
    vi k(m);
    vin(k);
    vi lf=prevSmaller(a);
    vi rf=nextSmallerEle(a);
    int s=0;
    for(int i=0;i<n;i++){
        int ct=((i+1)%mod)*((n-i)%mod)%mod;
        s=(s+(ct*binExpo(a[i],mod-2,mod))%mod)%mod;
    }
    vpi ci;
    for(int i=0;i<n;i++){
        int ct=((i-lf[i])*(rf[i]-i))%mod;
        ci.pb({a[i],ct});
    }
    sort(all(ci));
    vi a1(n+1),pr1(n+1),pr2(n+1),pr3(n+1);
    for(int i=1;i<=n;i++){
        int val=ci[i-1].ff;
        int ct=ci[i-1].ss;
        a1[i]=val;
        pr1[i]=(pr1[i-1]+ct)%mod;
        pr2[i]=(pr2[i-1]+(ct*val)%mod)%mod;
        pr3[i]=(pr3[i-1]+(ct*binExpo(val,mod-2,mod))%mod)%mod;
    }
    for(int i=0;i<m;i++){
        int k1=k[i];
        int idx=upper_bound(a1.begin()+1,a1.end(),k1)-a1.begin()-1;
        int l1=k1*pr1[idx]%mod,l2=pr2[idx],l3=2*pr1[idx]%mod;
        int l=(l1-l2+l3+mod)%mod;
        int r=((k1+1)*(pr3[n]-pr3[idx]+mod)%mod)%mod;
        int ans=((s+(l+r)%mod)%mod-pr3[n]+mod)%mod;
        cout<<ans<<endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}