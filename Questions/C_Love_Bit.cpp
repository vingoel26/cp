#include <bits/stdc++.h>
#define int long long
#define oka cout<<"YES"<<endl;
#define na cout<<"NO"<<endl;
using namespace std;

int32_t main() {
 int t;
 cin>>t;
 while(t--){
    int l,r;
    cin>>l>>r;
    int ans=0;
    int l1=((l-1)/4)*2;
    // cout<<l1<<endl;
    if((l-1)%4==2){
        l1++;
    }
    else if((l-1)%4==3){
        l1+=2;
    }
    int r1=((r)/4)*2;
    // cout<<r1<<endl;
    if((r)%4==2){
        r1++;
    }
    else if((r)%4==3){
        r1+=2;
    }
    // cout<<l1<<" "<<r1<<endl;
    cout<<r1-l1<<endl;
 }
}