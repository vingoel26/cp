#include <bits/stdc++.h>
using namespace std;

long long solve(int N, int M, vector<int> A, vector<vector<int>> edges) {
    vector<vector<int>> adj(N);
    vector<long long> deg(N, 0);
    for (const auto& edge : edges) {
        int u = edge[0] - 1; 
        int v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<long long> W = deg;
    sort(W.begin(), W.end());
    reverse(W.begin(), W.end());
    // pair<capacity_sum, node_degrees_in_component>
    vector<pair<long long, vector<long long>>> compsz;
    vector<int> seen(N, 0);
    
    // Find compsz via BFS
    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            long long s = 0;
            vector<long long> ndeg;
            queue<int> q;
            
            q.push(i);
            seen[i] = 1;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                s += A[u];
                ndeg.push_back(deg[u]);
                
                for (int v : adj[u]) {
                    if (!seen[v]) {
                        seen[v] = 1;
                        q.push(v);
                    }
                }
            }
            
            sort(ndeg.rbegin(), ndeg.rend());
            compsz.push_back({s, ndeg});
        }
    }
    
    // Sort compsz by capacity sum (ascending)
    sort(compsz.begin(), compsz.end());
    
    long long ans = 0;
    int w_idx = 0;
    for (const auto& comp : compsz) {
        for (long long d : comp.second) {
            ans += d * W[w_idx++];
        }
    }
    return ans;
}

int main() {
    // Test Case 1: Sample Input from Image
    // N=5, M=4, A={10,20,30,40,50}, Edges: (1,2), (2,3), (4,5), (1,3)
    // Expected: 14
    cout << "Test Case 1 (Sample): " << solve(5, 4, {10, 20, 30, 40, 50}, {{1, 2}, {2, 3}, {4, 5}, {1, 3}}) << endl;

    // Test Case 2: Star Topology (High Degree Central Node)
    // N=4, M=3, A={100, 10, 10, 10}, Edges: (1,2), (1,3), (1,4)
    // Expected: 12
    cout << "Test Case 2 (Star): " << solve(4, 3, {100, 10, 10, 10}, {{1, 2}, {1, 3}, {1, 4}}) << endl;

    // Test Case 3: Tied Capacity Sums
    // N=4, M=2, A={10, 10, 10, 10}, Edges: (1,2), (3,4)
    // Both compsz have sum 20. Order doesn't matter.
    // Expected: 4 (1*1 + 1*1 + 1*1 + 1*1)
    cout << "Test Case 3 (Ties): " << solve(4, 2, {10, 10, 10, 10}, {{1, 2}, {3, 4}}) << endl;

    // Test Case 4: No Edges (M=0)
    // Expected: 0
    cout << "Test Case 4 (No Edges): " << solve(3, 0, {10, 20, 30}, {}) << endl;

    // Test Case 5: Single Node
    // Expected: 0
    cout << "Test Case 5 (Single Node): " << solve(1, 0, {50}, {}) << endl;

    return 0;
}