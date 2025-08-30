#include<bits/stdc++.h>
using namespace std;

vector<int> dp1(1000005, -2);
vector<int> s;
int n1, k;
int dp(int n)
{
    if(n==0){
        return 0;
    }
    if(dp1[n]!=-2){
        return dp1[n];
    }
    int ans=1e9;
    for(int i=0;i<n1;i++){
        int q=n-s[i];
        int c=0;
        if(q<0){
            continue;
        }
        else{
            c++;
            c+=dp(q);
        }
        if(c!=0){
            ans=min(ans,c);
        }
    }
    // cout<<ans<<endl;
    if(ans==1e9){
        ans=-1;
    }
    dp1[n]=ans;
    return dp1[n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    vector<int> dp(k + 1, -2);
    int ans = dp(n);
    cout << ans << endl;
    return 0;
}