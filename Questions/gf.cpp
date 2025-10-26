#include <bits/stdc++.h>

#define int long long
using namespace std;

vector < int > prime(int n) {
    vector < int > ans;

    if (n % 2 == 0) {
        ans.push_back(2);
        while (n % 2 == 0) {
            n = n / 2;
        }
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0) {
            ans.push_back(i);
            while (n % i == 0) {
                n = n / i;
            }
        }
    }
    if (n > 2)
        ans.push_back(n);

    return ans;
}

int32_t main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        int a[n];
        int e = 0;
        int mx=0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx=max(mx,a[i]);
            if (a[i] % 2 == 0) {
                e++;
            }
        }

        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        // mx=sqrt(mx)+1;
        if (e >= 2) {
            cout << 0 << endl;
            continue;
        }
        map<int,int> vis;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            vector < int > p = prime(a[i]);
            for (auto x: p) {
                vis[x]++;
                if (vis[x] > 1) {
                    ans = true;
                    break;
                }
            }
        }
        if (ans) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            vector < int > p = prime(a[i] + 1);
            for (auto x: p) {

                if (vis[x] > 0) {
                    ans = true;
                    break;
                }
            }

        }
        if (ans) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }



    }

}