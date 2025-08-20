#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    int mx=0;
    long long s=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
        mx=max(mx,v[i]);
    }
    int low=mx,high=s;
    while(low<=high){
        long long mid=low+((high-low)/2);
        int s1=0;
        int ct=0;
        for(int i=0;i<n;i++){
            if(s1+v[i]>mid){
                ct++;
                s1=v[i];
            }
            else{
                s1+=v[i];
            }
        }
        if(ct>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<low<<endl;
}