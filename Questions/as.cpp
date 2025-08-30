#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ct = 0;
    int a[4] = {1, 2, 5, 10};
    for (int i = 3; i >= 0; i--)
    {
        while (n >= a[i])
        {
            n -= a[i];
            ct++;
        }
    }
    cout<<ct<<endl;
}