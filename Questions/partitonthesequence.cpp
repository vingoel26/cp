#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // int n1=(n+k-1)/k;
    vector<vector<char>> v(k);
    for (int i = 0; i < n; i++)
    {
        v[i % k].push_back(s[i]);
    }
    for (int i = 0; i < k; ++i)
    {
        for (char c : v[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }
    // int ans = 0;
    // for (auto it : v)
    // {
    //     int mx = 0;
    //     int s = 0;
    //     map<char, int> mp;
    //     for (int i = 0; i < it.size(); i++)
    //     {
    //     }
    // }
}