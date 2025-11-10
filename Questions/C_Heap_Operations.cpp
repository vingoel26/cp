#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> ans;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int x;
            cin >> x;
            q.push(-x);
            ans.push_back({s, x});
        }
        else if (s == "getMin")
        {
            int x;
            cin >> x;
            while (!q.empty() && -q.top() < x)
            {
                q.pop();
                ans.push_back({"removeMin", 1e9 + 5});
            }
            if (q.empty() || -q.top() > x)
            {
                q.push(-x);
                ans.push_back({"insert", x});
            }
            ans.push_back({s, x});
        }
        else
        {
            if (q.empty())
            {
                ans.push_back({"insert", 0});
            }
            else
            {
                q.pop();
            }
            ans.push_back({s, 1e9 + 5});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " ";
        if (ans[i].second != 1e9 + 5)
        {
            cout << ans[i].second;
        }
        cout << endl;
    }
}