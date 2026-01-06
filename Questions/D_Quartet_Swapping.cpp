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
    for (int i = 1; i <= n; ++i) \
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
int merge_count(vector<int> &a, vector<int> &tmp, int l, int r) {
    if (r - l <= 1) return 0;

    int m = (l + r) / 2;
    int inv = 0;

    inv ^= merge_count(a, tmp, l, m);
    inv ^= merge_count(a, tmp, m, r);

    int i = l, j = m, k = l;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] < a[j])) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            inv ^= ((m - i) & 1);
        }
    }

    for (int p = l; p < r; p++) a[p] = tmp[p];
    return inv;
}

int check(vector<int> a) {
    vector<int> tmp(a.size());
    return merge_count(a, tmp, 0, a.size());
}
void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vin(a);
    vi o,e;
    for(int i=0;i<n;i++){
        if(i%2==1){
            e.pb(a[i]);
        }
        else{
            o.pb(a[i]);
        }
    }
    vi o1=o;
    vi e1=e;
    vi ans(n+1);
    sort(all(o1));
    sort(all(e1));
    int j=0,k=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            ans[i]=e1[j];
            j++;
        }
        else{
            ans[i]=o1[k];
            k++;
        }
    }
    if(check(e)!=check(o)){
        swap(ans[n],ans[n-2]);
    }
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