#include <bits/stdc++.h>
#define int long long
#define inp(n) \
    int n;     \
    cin >> n
#define vin(a) \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> a[i];            \
    }
#define vout(a) \
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
using namespace std;

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
    vector<vector<pair<int,int>>> adj(n+m+1);
    vi colour(n+m+1,-1);
    int f=n+1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        if(s=="crewmate"){
            adj[a].pb({f,1});
            adj[f].pb({a,1});
            adj[f].pb({b,1});
            adj[b].pb({f,1});
            f++;
        }
        else{
            adj[b].pb({a,1});
            adj[a].pb({b,1});
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(colour[i]==-1){
            vi c(2);
            colour[i]=1;
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int u = st.top(); 
                st.pop();
                if(u <= n) {
                    c[colour[u]]++;
                }
                for(auto &pr : adj[u]){
                    int v = pr.ff;
                    int w = pr.ss;
                    int c1 = colour[u] ^ w;
                    if(colour[v] == -1){
                        colour[v] = c1;
                        st.push(v);
                    } 
                    else if(colour[v] != c1){
                        cout<<-1<<endl;
                        return;
                    }
                }
            }
            ans += max(c[0], c[1]);
        }
    }
    cout<<ans<<endl;
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