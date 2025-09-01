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

/*
========================================
Author:         Vinayak Goel
Institution:    IIITL
May the WA avoid you
========================================
*/

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.first != b.first){
		if(a.first < b.first) return true;
		return false;
    }else{
		if(a.second < b. second) return true;
		return false;
	}
}
void solve()
{
    int n;
    cin>>n;
    vpi a;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a.pb({l,r});
    }
    sort(all(a),comp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }
    int a1=-1,a2=-1;
    for(int i=0;i<n;i++){
        if(a[i].first>a1){
            a1=a[i].second;
        }
        else if(a[i].first>a2){
            a2=a[i].second;
        }
        else{
            nah
            return;
        }
    }
    yah
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}