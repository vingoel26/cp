#include <bits/stdc++.h>
using namespace std;

long long oreConveyor(int n, int m, long long b, vector<int> weight) {
    long long mx = 0;
    long long s = 0;
    for (int w : weight) {
        mx = max(mx, (long long)w);
        s += w;
    }
    long long  l=mx,r=s,ans=s;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        int ct = 1;
        long long curs = weight[0];
        long long mxcur = weight[0];
        long long mncur = weight[0];
        for (int i = 1; i < n; ++i) {
            long long mn1 = min(mncur, (long long)weight[i]);
            long long mx1 = max(mxcur, (long long)weight[i]);
            if (curs + weight[i] > mid || mx1 - mn1 > b) {
                ct++;           
                mncur = weight[i];      
                curs = weight[i];    
                mxcur = weight[i];     
            } else {
                mncur = mn1;
                curs += weight[i];
                mxcur = mx1;
            }
        }
        if (ct <= m) {
            r = mid - 1; 
            ans = mid; 
        } else {
            l = mid + 1;
        }
    }

    return ans;
}
int main() {
    // Boilerplate from your platform
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    long long B;
    cin >> B;
    vector<int> weight(N);
    for(int i_weight = 0; i_weight < N; i_weight++) {
        cin >> weight[i_weight];
    }
    
    long long out_;
    out_ = oreConveyor(N, M, B, weight);
    cout << out_;
    
    return 0;
}