#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

long long solve(int N, int K, vector<long long> A) {
    // 1. The Simplest Preprocessing: std::map does all the heavy lifting natively
    map<long long, long long> counts;
    for (long long x : A) {
        counts[x]++;
    }
    
    vector<long long> vals;
    vector<long long> pref; 
    
    long long current_sum = 0;
    for (auto const& [val, freq] : counts) {
        vals.push_back(val);
        current_sum += freq;
        pref.push_back(current_sum); // Prefix sums of frequencies
    }
    0
    int M = vals.size();
    
    // Quick helper for score
    auto get_score = [&](int L, int R) -> long long {
        if (L > R) return 0;
        if (L == 0) return pref[R];
        return pref[R] - pref[L - 1];
    };

    long long max_score = 0;

    // 2. Standard Progressions (Direct Translation of Rules)
    for (int i = 0; i < M; i++) {
        long long b = vals[i];
        if (b < 2) continue; // Base >= 2
        
        int pos = i;
        long long expected = b; 
        
        for (int step = 1; step <= K; step++) {
            if (expected > 1e18 / b) break; // Safe overflow check
            expected *= b;
            
            // Search in suffix [pos ... M-1]
            auto it = lower_bound(vals.begin() + pos, vals.end(), (long long)expected);
            if (it == vals.end()) break; // No such index p exists
            
            int p = distance(vals.begin(), it);
            
            if (vals[p] == (long long)expected) {
                max_score = max(max_score, get_score(i, p));
            }
            
            pos = p; // RULE: ALWAYS update position, even on failure
        }
    }
    
    // 3. Perfect Square Progressions (Direct Translation of Rules)
    for (int i = 0; i < M; i++) {
        long long v = vals[i];
        long long root = round(sqrt(v));
        
        if (root >= 2 && root * root == v) {
            int pos = i;
            __int128 expected = v;
            
            for (int step = 1; step <= K; step++) {
                expected *= v;
                if (expected > 1e18) break;
                
                auto it = lower_bound(vals.begin() + pos, vals.end(), (long long)expected);
                if (it == vals.end()) break;
                
                int p = distance(vals.begin(), it);
                
                if (vals[p] == (long long)expected) {
                    max_score = max(max_score, get_score(i, p));
                    pos = p; // RULE: ONLY update position on success
                } else {
                    break;   // RULE: TERMINATE IMMEDIATELY on failure
                }
            }
        }
    }
    
    return max_score;
}
int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // If your problem doesn't have multiple test cases per run, 
    // you can remove the "cin >> T" loop and just run the inside block once.
    if (!(cin >> T)) return 0; 

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << solve(N, K, A) << "\n";
    }

    return 0;
}