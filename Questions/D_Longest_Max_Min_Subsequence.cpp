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
#define mod 1000000007
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
int INF=1e18+7;
struct Node {
    int val;
    int idx;
};
struct MaxSegTree {
    int n;
    vector<Node> tree;

    MaxSegTree(int n) : n(n) {
        tree.resize(4 * n);
    }

    Node combine(Node a, Node b) {
        if (a.val > b.val) return a;
        if (a.val < b.val) return b;
        return {a.val, min(a.idx, b.idx)};
    }

    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = {a[start], start};
            return;
        }
        int mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] = {-INF, idx};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx);
        else update(2 * node + 1, mid + 1, end, idx);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {-INF, INF};
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return combine(query(2 * node, start, mid, l, r),query(2 * node + 1, mid + 1, end, l, r));
    }
};

struct MinSegTree {
    int n;
    vector<Node> tree;

    MinSegTree(int n) : n(n) {
        tree.resize(4 * n);
    }

    Node combine(Node a, Node b) {
        if (a.val < b.val) return a;
        if (a.val > b.val) return b;
        return {a.val, min(a.idx, b.idx)};
    }

    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = {a[start], start};
            return;
        }
        int mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] = {INF, idx};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx);
        else update(2 * node + 1, mid + 1, end, idx);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return {INF, INF};
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return combine(query(2 * node, start, mid, l, r),query(2 * node + 1, mid + 1, end, l, r));
    }
};
void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    viv pos(n+1);
    vi pos1(n+1,-1);
    int ct=0;
    for(int i=0;i<n;i++){
        if(pos1[a[i]]==-1){
            ct++;
        }
        pos[a[i]].pb(i);
        pos1[a[i]]=i;
    }
    MaxSegTree mxtree(n);
    mxtree.build(a,1,0,n-1);
    MinSegTree mntree(n);
    mntree.build(a,1,0,n-1);
    set<int> lst;
    for(int i=1;i<=n;i++){
        if(pos1[i]!=-1){
            lst.insert(pos1[i]);
        }
    }
    int st=0;
    vi ans;
    for(int i=1;i<=ct;i++){
        int r=*lst.begin();
        Node ans1;
        if(i%2==1){
            ans1=mxtree.query(1,0,n-1,st,r);
        }
        else{
            ans1=mntree.query(1,0,n-1,st,r);
        }
        int val=ans1.val;
        int idx=ans1.idx;
        ans.pb(val);
        st=idx+1;
        lst.erase(pos1[val]);
        for(int id:pos[val]){
            mxtree.update(1,0,n-1,id);
            mntree.update(1,0,n-1,id);
        }
    }
    cout<<ct<<endl;
    vout(ans);
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