#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<int>st;
    st.push(0);
    int ans = 0;
    for(int i = 1;i<=s.size();i++)
    {
        if(s[i-1]=='(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                ans = max(ans,i-st.top());
            }
        }
    }
    cout<<ans<<endl;
}