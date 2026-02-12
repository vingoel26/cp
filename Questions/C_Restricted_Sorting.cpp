#include <bits/stdc++.h>
using namespace std;

int main()
{
    int parity;
    cout<<"Enter the parity ";
    cin>>parity;
    string s;
    cout<<"Enter the transmitted part ";
    cin>>s;

    int parityc=0;
    for(auto val:s){
        if(val=='1') parityc^=1;
    }

    if(parity==parityc){
        cout<<"Yes"<<endl;
    }

    else{
        cout<<"No"<<endl;
    }

}