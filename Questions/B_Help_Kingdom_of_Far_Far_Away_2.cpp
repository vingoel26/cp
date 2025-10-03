#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
        {
            continue;
        }
        if (s[i] == '.')
        {
            break;
        }
        l++;
    }
    int k = l % 3;
    if (k == 0)
    {
        k = 3;
    }
    string ans;
    if (s[0] == '-')
    {
        ans.push_back('(');
    }
    ans.push_back('$');
    int ct = 0;
    if (s[0] != '-')
    {
        l--;
    }
    for (int i = 0; i <= l; i++)
    {
        if (s[i] == '-')
        {
            continue;
        }
        ct++;
        ans.push_back(s[i]);
        if (ct == k)
        {
            ans.push_back(',');
            k = 3;
            ct = 0;
        }
    }
    if (ans[ans.size() - 1] == ',')
    {
        ans.pop_back();
    }
    ans.push_back('.');
    for (int i = 0; i < 2; i++)
    {
        if (l + 2 >= n)
        {
            ans.push_back('0');
        }
        else
        {
            ans.push_back(s[l + 2]);
        }
        l++;
    }
    if (s[0] == '-')
    {
        ans.push_back(')');
    }
    cout << ans << endl;
}