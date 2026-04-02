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

struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
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
vector<pair<long long,int>>segmentTree;
pair<long long,int> merge(pair<long long,int>&p1,pair<long long,int>&p2){
    return {p1.first+p2.first,p1.second+p2.second};
}
void update(int l,int r,int index,int pos){
    if(l==r){
        segmentTree[index].first+=pos;
        segmentTree[index].second++;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        update(l,mid,2*index,pos);
    }
    else{
        update(mid+1,r,2*index+1,pos);
    }
    segmentTree[index]=merge(segmentTree[2*index],segmentTree[2*index+1]);
}
int query(int l,int r,int index,long long sum){
    if(l==r){
        return min(segmentTree[index].second,(int)sum/l);
    }
    int mid=(l+r)/2;
    if(segmentTree[2*index].first<=sum){
        return segmentTree[2*index].second + query(mid+1,r,2*index+1,sum-segmentTree[2*index].first);
    }
    return query(l,mid,2*index,sum);
}
void solve()
{
    int n,q;
	cin >>n>>q;
	vector<int>v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	segmentTree.assign(4*n,{0,0});
	vector<pair<int,pair<int,int>>>qr;
	for(int i=0;i<q;i++){
	    int x,y;
	    cin>>x>>y;
	    x--;
	    qr.push_back({x,{y,i}});
	}
	sort(qr.begin(),qr.end());
    vector<int>ans(q);
    int prev=0;
    for(int i=0;i<q;i++){
        int x=qr[i].first;
        int y=qr[i].second.first;
        int index=qr[i].second.second;
        while(prev<=x){
           update(1,n,1,v[prev]);
           prev++;
        }
        ans[index]= query(1,n,1,y);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
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