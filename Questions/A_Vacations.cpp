#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> d(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        int x = a[i - 1];
        d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
        if (x == 1 or x == 3)
        {
            d[i][1] = max(d[i - 1][0], d[i - 1][2]) + 1;
        }
        if (x == 2 or x == 3)
        {
            d[i][2] = max(d[i - 1][0], d[i - 1][1]) + 1;
        }
    }
    int ans = max(d[n][0], max(d[n][1], d[n][2]));
    cout << n - ans << endl;
    return 0;
}