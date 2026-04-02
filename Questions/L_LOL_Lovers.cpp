#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, string Arr, vector<vector<int>>& Edges) {
    // Adjacency list storing pairs of (character, connected_vertex)
    vector<vector<pair<char, int>>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u = Edges[i][0];
        int v = Edges[i][1];
        char c = Arr[i];
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    // Sort adjacency lists in descending order of characters.
    for (int i = 1; i <= N; ++i) {
        sort(adj[i].rbegin(), adj[i].rend());
    }

    vector<int> ans(N);
    vector<int> visited(N + 1, 0);

    // Run the simulation for each vertex as a starting point
    for (int i = 1; i <= N; ++i) {
        vector<int> active = {i};
        visited[i] = i; 

        while (true) {
            char max_c = -1;
            
            // 1. Find the maximum character among valid next edges
            for (int u : active) {
                for (auto& edge : adj[u]) {
                    char c = edge.first;
                    int v = edge.second;
                    if (visited[v] != i) {
                        if (c > max_c) {
                            max_c = c;
                        }
                        break; 
                    }
                }
            }

            if (max_c == -1) break; 

            // 2. Extend the paths only along the edges that match the max character
            vector<int> next_active;
            for (int u : active) {
                for (auto& edge : adj[u]) {
                    char c = edge.first;
                    int v = edge.second;
                    if (visited[v] != i) {
                        if (c == max_c) {
                            visited[v] = i;
                            next_active.push_back(v);
                        } else if (c < max_c) {
                            break; 
                        }
                    }
                }
            }
            active = move(next_active);
        }

        // 3. Pick the maximum vertex number out of the final endpoints
        int best_v = -1;
        for (int v : active) {
            if (v > best_v) {
                best_v = v;
            }
        }
        ans[i - 1] = best_v;
    }

    return ans;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read until EOF to easily process multiple test cases if testing locally via file redirection
    while (cin >> N) {
        string Arr;
        cin >> Arr;

        vector<vector<int>> Edges(N - 1, vector<int>(2));
        for (int i = 0; i < N - 1; ++i) {
            cin >> Edges[i][0] >> Edges[i][1];
        }

        vector<int> result = solve(N, Arr, Edges);

        for (int i = 0; i < N; ++i) {
            cout << result[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}