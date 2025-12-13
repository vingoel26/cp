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
    string s,t;
    cin>>s>>t;
    map<char,int>mp,mp1;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<m;i++){
        mp1[t[i]]++;
    }
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    set<char>st;
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    for(auto it:st){
        if(mp1[it]<mp[it]){
            cout<<"Impossible"<<endl;
            return;
        }
        else{
            mp1[it]-=mp[it];
            if(mp1[it]==0){
                mp1.erase(it);
            }
        }
    }
    string ans="";
    int i=0;
    while(i<n){
        if(!mp1.empty() and mp1.begin()->ff<s[i]){
            ans+=mp1.begin()->ff;
            mp1.begin()->ss--;
            if(mp1.begin()->ss==0){
                mp1.erase(mp1.begin()->ff);
            }
        }
        else{
            ans+=s[i];
            i++;
        }
    }
    while(!mp1.empty()){
        ans+=mp1.begin()->ff;
        mp1.begin()->ss--;
        if(mp1.begin()->ss==0){
            mp1.erase(mp1.begin()->ff);
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