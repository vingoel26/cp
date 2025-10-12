#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                r=i;
                break;
            }
        }
        if(l==r){
            cout<<0<<endl;
        }
        else{
            cout<<r-l+1-(count(s.begin()+l,s.begin()+r+1,'1'))<<endl;
        }
    }
}