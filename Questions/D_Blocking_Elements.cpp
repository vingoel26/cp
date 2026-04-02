#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

long long nCrSmall(long long n, int r, const vector<long long>& invfact) {
    if (n < r) return 0;
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = (res * ((n - i) % MOD)) % MOD;
    }
    res = (res * invfact[r]) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<long long> fact(7), invfact(7);
    fact[0] = 1;
    for (int i = 1; i <= 6; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[6] = modpow(fact[6], MOD - 2);
    for (int i = 5; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    while (T--) {
        long long N;
        cin >> N;
        vector<long long> s(5);
        for (int i = 0; i < 5; i++) cin >> s[i];

        long long sum = 0, sq = 0;
        for (int i = 0; i < 5; i++) {
            sum = (sum + s[i]) % MOD;
            sq = (sq + (s[i] % MOD) * (s[i] % MOD)) % MOD;
        }

        long long pairSum = (sum * sum - sq) % MOD;
        if (pairSum < 0) pairSum += MOD;

        long long ans = 0;
        long long coeff[6] = {0, 0, 1, 6, 18, 24};

        for (int m = 2; m <= 5; m++) {
            if (N < m) continue;
            long long waysPairs = coeff[m];
            long long choosePos = nCrSmall(N + 1, m + 1, invfact);
            long long consonants = modpow(21, N - m);

            long long cur = pairSum;
            cur = (cur * waysPairs) % MOD;
            cur = (cur * choosePos) % MOD;
            cur = (cur * consonants) % MOD;

            ans = (ans + cur) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}