#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<char>> v(k);
    for (int i = 0; i < n; i++)
    {
        v[i % k].push_back(s[i]);
    }
    int ans = 0;
    for (auto it : v)
    {
        int mx = 0;
        int s = 0;
        map<char, int> mp;
        for (int i = 0; i < it.size(); i++)
        {
            mp[it[i]]++;
        }
        for(auto it1 : mp){
            mx=max(mx,it1.second);
            s+=it1.second;
        }
        ans+=s-mx;
    }
    cout<<ans;
}