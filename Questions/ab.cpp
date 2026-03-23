#include <bits/stdc++.h>
using namespace std;

long long signalBoosters(int N, int K, vector<long long> pos) {
    long long l = 1;
    long long r = pos[pos.size()-1] - pos[0];
    long long ans = r;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long cnt = 0;
        for (int i = 0; i < (int)pos.size() - 1; ++i) {
            long long dif = pos[i+1] - pos[i];
            cnt += (dif - 1) / mid;
        }
        if (cnt <= K) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    // Read N and K. If no input is provided, exit cleanly.
    if (cin >> N >> K) {
        vector<long long> pos(N);
        for (int i = 0; i < N; ++i) {
            cin >> pos[i];
        }

        // Print the result
        cout << signalBoosters(N, K, pos) << "\n";
    }

    return 0;
}
