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
bool vis[7][7];

void solve(string& s, int i, int x, int y, int& ans){
    if(i == 48){
        if(x == 6 && y == 0){ 
            ans++;
        }
        return;
    }
    
    if(x == 6 && y == 0) return;
    
    bool can_u = (x > 0 && !vis[x-1][y]);
    bool can_d = (x < 6 && !vis[x+1][y]);
    bool can_l = (y > 0 && !vis[x][y-1]);
    bool can_r = (y < 6 && !vis[x][y+1]);
    
    if(!can_u && !can_d && can_l && can_r) return;
    if(can_u && can_d && !can_l && !can_r) return;
    
    vis[x][y] = true;
    
    if(s[i] == '?'){
        int dx[] = {1, -1, 0, 0}; 
        int dy[] = {0, 0, -1, 1};
        
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx >= 0 && nx <= 6 && ny >= 0 && ny <= 6 && !vis[nx][ny]){
                solve(s, i+1, nx, ny, ans);
            }
        }
    } else {
        int nx = x, ny = y;
        if(s[i]=='D') nx++;
        else if(s[i]=='U') nx--;
        else if(s[i]=='L') ny--;
        else ny++;
        
        if(nx >= 0 && nx <= 6 && ny >= 0 && ny <= 6 && !vis[nx][ny]){
            solve(s, i+1, nx, ny, ans);
        }
    }
    
    vis[x][y] = false;
}

void solve1(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            vis[i][j] = false;
        }
    }
    
    solve(s, 0, 0, 0, ans);
    cout << ans << endl;
}

int32_t main(){
    fast
    int t = 1;
    while(t--){
        solve1();
    }
    return 0;
}