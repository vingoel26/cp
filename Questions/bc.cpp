#include <bits/stdc++.h>
using namespace std;

int main() {

  int n,W;
  cin>>n>>W;
  int w[n],val[n];
  for(int i=0;i<n;i++){
      cin>>val[i];
  }
  for(int i=0;i<n;i++){
      cin>>w[i];
  }
  int dp[n+1][W+1];
  for(int i=0;i<=n;i++){
      for(int j=0;j<=W;j++){
          if(i==0 or j==0){
            dp[i][j]=0;
            continue;
        }
      }
  }
  for(int i=1;i<=n;i++){
      for(int j=1;j<=W;j++){
        if(j<w[i-1]){
            dp[i][j]=dp[i-1][j];
        }
        else{
          dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-w[i-1]]);
        }
      }
  }
  cout<<dp[n][W]<<endl;
  

}