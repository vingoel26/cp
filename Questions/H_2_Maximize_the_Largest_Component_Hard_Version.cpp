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
    int n,m;
    cin>>n>>m;
    vector<string>a(n);
    vin(a);
    vi ctr(n);
    vi ctc(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                ctr[i]++;
                ctc[j]++;
            }
        }
    }
    viv comp(n,vi(m,0));
    stack<pair<int,int>>st;
    int c=0;
    vi rmn(n*m+1,n),cmn(n*m+1,m),rmx(n*m+1,-1),cmx(n*m+1,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#' and comp[i][j]==0){
                c++;
                st.push({i,j});
                comp[i][j]=c;
                int rmn1=i,cmn1=j,rmx1=i,cmx1=j;
                while(!st.empty()){
                    auto p=st.top();
                    st.pop();
                    int x=p.ff,y=p.ss;
                    rmn[c]=min(rmn[c],x);
                    cmn[c]=min(cmn[c],y);
                    rmx[c]=max(rmx[c],x);
                    cmx[c]=max(cmx[c],y);
                    if(x>0 and a[x-1][y]=='#' and comp[x-1][y]==0){
                        comp[x-1][y]=c;
                        st.push({x-1,y});
                    }
                    if(x<n-1 and a[x+1][y]=='#' and comp[x+1][y]==0){
                        comp[x+1][y]=c;
                        st.push({x+1,y});
                    }
                    if(y>0 and a[x][y-1]=='#' and comp[x][y-1]==0){
                        comp[x][y-1]=c;
                        st.push({x,y-1});
                    }
                    if(y<m-1 and a[x][y+1]=='#' and comp[x][y+1]==0){
                        comp[x][y+1]=c;
                        st.push({x,y+1});
                    }
                }
            }
        }
    }
    vi sz(c+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(comp[i][j]!=0){
                sz[comp[i][j]]++;
            }
        }
    }
    vi r(n+2),cm(m+2);
    viv diff(n+2,vi(m+2,0));
    for(int i=1;i<=c;i++){
        int r1=max(0LL,rmn[i]-1);
        int r2=min(n-1,rmx[i]+1);
        int c1=max(0LL,cmn[i]-1);
        int c2=min(m-1,cmx[i]+1);
        r[r1]+=sz[i];
        r[r2+1]-=sz[i];
        cm[c1]+=sz[i];
        cm[c2+1]-=sz[i];
        r1++,r2++,c1++,c2++;
        diff[r1][c1]+=sz[i];
        diff[r1][c2+1]-=sz[i];
        diff[r2+1][c1]-=sz[i];
        diff[r2+1][c2+1]+=sz[i];
    }
    for(int i=1;i<=n;i++){
        r[i]+=r[i-1];
    }
    for(int i=1;i<=m;i++){
        cm[i]+=cm[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ct1=ctr[i]+ctc[j];
            if(a[i][j]=='.'){
                ct1--;
            }
            int ans1=ct1+r[i]+cm[j]-diff[i+1][j+1];
            mx=max(mx,ans1);
        }
    }
    cout<<mx<<endl;
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