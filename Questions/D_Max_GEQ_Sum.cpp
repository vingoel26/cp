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
#define vppi vector<vector<pair<int,int>>>
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
const int MAXN = 200005;
long long st_max[MAXN][20];
long long st_min[MAXN][20];
int Log[MAXN];
void build(int n,vi P) {
    for (int i = 0; i <= n; i++) {
        st_max[i][0] = P[i];
        st_min[i][0] = P[i];
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j) <= n + 1; i++) {
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
        }
    }
}

long long query_max(int L, int R) {
    int k = Log[R - L + 1];
    return max(st_max[L][k], st_max[R - (1 << k) + 1][k]);
}

long long query_min(int L, int R) {
    int k = Log[R - L + 1];
    return min(st_min[L][k], st_min[R - (1 << k) + 1][k]);
}
vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && arr[stk.top()] < arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            res[i] = stk.top();
        }
        stk.push(i);
    }
    return res;
}
vector<int> preGreaterEle(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); 
    stack<int> st; 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
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
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    vi pr(n+1);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+a[i-1];
    }
    build(n,pr);
    vi r=nextLargerElement(a);
    vi l=preGreaterEle(a);
    for(int i=0;i<n;i++){
        int mx=query_max(i+1,r[i]);
        int mn=query_min(l[i]+1,i);
        if(mx-mn>a[i]){
            nah
            return;
        }
    }
    yah
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
    Log[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        Log[i] = Log[i / 2] + 1;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}