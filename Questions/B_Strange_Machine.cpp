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



void solve()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vi p;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            p.pb(i+1);
        }
    }
    if(p.size()==0){
        for(int i=0;i<q;i++){
            int a;
            cin>>a;
            cout<<a<<endl;
        }
    }
    else{
        for(int i=0;i<q;i++){
            int a;
            cin>>a;
            int pos=1;
            int ans=0;
            while(a>0){
                if(s[pos-1]=='B'){
                    a=a/2;
                    ans+=1;
                    if(pos==n){
                        pos=1;
                    }
                    else{
                        pos++;
                    }
                }
                else{
                    auto it=lower_bound(all(p),pos);
                    int nxt;
                    if(it==p.end()){
                        nxt=p[0]+n;
                    }
                    else{
                        nxt=*it;
                    }
                    int d=nxt-pos;
                    ans+=min(a,d);
                    int k=min(a,d);
                    a-=k;
                    pos=((pos+k-1)%n)+1;
                }
            }
            cout<<ans<<endl;
        }
    }
}

int32_t main()
{
    fast
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}