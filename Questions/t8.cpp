#include <bits/stdc++.h>
using namespace std;

int main() {
    string x,y;
    cin>>x>>y;
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1])
                {dp[i][j] = dp[i - 1][j - 1] + 1;}
            else
                {dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);}
        }
    }
    cout << dp[m][n] << endl;
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs += x[i - 1];
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            {i--;}
        else
            {j--;}
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;
}
