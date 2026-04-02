#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// --- Global Variables ---
int N, E, C, D;
long long lambda_val;
vector<long long> P, I;
vector<pair<int, int>> input_edges;
vector<pair<int, int>> edges;
vector<vector<int>> adj;        // Directed edges
vector<vector<int>> rev_adj;    // Reversed directed edges
vector<vector<int>> undirected; // For clusters

vector<int> current_colors;
long long max_score = -2e18;    // Track best valid score
vector<int> best_colors;


// --- 1. Check Neighborhood Diversity Rule ---
bool checkDiversity() {
    for (int i = 1; i <= N; ++i) {
        set<int> neighbor_colors;
        int total_neighbors = 0;
        
        for (int u : adj[i]) { neighbor_colors.insert(current_colors[u]); total_neighbors++; }
        for (int u : rev_adj[i]) { neighbor_colors.insert(current_colors[u]); total_neighbors++; }
        
        if (total_neighbors < D) {
            if (neighbor_colors.size() != total_neighbors) return false;
        } else {
            if (neighbor_colors.size() < D) return false;
        }
    }
    return true;
}

// --- 2. Check Path Color Sequence Rule (No Arithmetic Progressions) ---
bool hasAP(const vector<int>& path) {
    if (path.size() < 3) return false;
    int n = path.size();
    int diff = current_colors[path[n-1]] - current_colors[path[n-2]];
    if (current_colors[path[n-2]] - current_colors[path[n-3]] == diff) return true;
    return false;
}

bool dfs_ap(int node, vector<int>& path) {
    path.push_back(node);
    if (hasAP(path)) {
        path.pop_back();
        return true; // Found an AP
    }
    for (int next_node : adj[node]) {
        if (dfs_ap(next_node, path)) return true;
    }
    path.pop_back();
    return false;
}

bool checkNoAP() {
    for (int i = 1; i <= N; ++i) {
        vector<int> path;
        if (dfs_ap(i, path)) return false; // Invalid if any path has an AP
    }
    return true;
}

// --- 3. Check Dominant Path Rule (Strictly Increasing) ---
bool dfs_dominant(int node, int last_color, vector<int>& out_degrees) {
    if (out_degrees[node] == 0) return true; // Reached valid exit point
    
    for (int next_node : adj[node]) {
        if (current_colors[next_node] > last_color) {
            if (dfs_dominant(next_node, current_colors[next_node], out_degrees)) return true;
        }
    }
    return false;
}

bool checkDominantPath() {
    vector<int> in_degrees(N + 1, 0);
    vector<int> out_degrees(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        out_degrees[i] = adj[i].size();
        in_degrees[i] = rev_adj[i].size();
    }
    
    for (int i = 1; i <= N; ++i) {
        if (in_degrees[i] == 0) {
            // Must start with a strictly increasing path
            if (dfs_dominant(i, current_colors[i], out_degrees)) return true;
        }
    }
    return false;
}

// --- Calculate the Final Score ---
long long calculateScore() {
    long long defense_strength = 0;
    long long penalty = 0;
    
    // Base strength
    for (int i = 1; i <= N; ++i) {
        defense_strength += P[current_colors[i]] * adj[i].size();
    }
    
    // Interference penalty
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        penalty += (I[current_colors[u]] * I[current_colors[v]]);
    }
    defense_strength -= (lambda_val * penalty);
    
    // Stability Bonus (Clusters)
    vector<bool> visited(N + 1, false);
    long long stability_bonus = 1;
    bool cluster_found = false;
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int cluster_size = 0;
            vector<int> q = {i};
            visited[i] = true;
            
            while (!q.empty()) {
                int curr = q.back();
                q.pop_back();
                cluster_size++;
                
                for (int neighbor : undirected[curr]) {
                    if (!visited[neighbor] && current_colors[neighbor] == current_colors[curr]) {
                        visited[neighbor] = true;
                        q.push_back(neighbor);
                    }
                }
            }
            if (cluster_size >= 2) {
                stability_bonus *= cluster_size;
                cluster_found = true;
            }
        }
    }
    
    if (!cluster_found) stability_bonus = 1;
    return defense_strength * stability_bonus;
}

// --- Backtracking to try all color combinations ---
void solve(int node) {
    if (node > N) {
        // Validation pipeline
        if (!checkDiversity()) return;
        if (!checkNoAP()) return;
        if (!checkDominantPath()) return;
        
        long long current_score = calculateScore();
        if (current_score > max_score) {
            max_score = current_score;
            best_colors = current_colors;
        }
        return;
    }
    
    // Try all colors for the current node (1-indexed)
    for (int c = 1; c <= C; ++c) {
        current_colors[node] = c;
        solve(node + 1);
    }
}

// --- Graph Builder for Subsets ---
void build_graph(int mask) {
    adj.assign(N + 1, vector<int>());
    rev_adj.assign(N + 1, vector<int>());
    undirected.assign(N + 1, vector<int>());
    edges.clear();

    for (int i = 0; i < E; ++i) {
        if ((mask & (1 << i)) != 0) { // If the i-th edge is kept
            int u = input_edges[i].first;
            int v = input_edges[i].second;
            edges.push_back({u, v});
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
            undirected[u].push_back(v);
            undirected[v].push_back(u);
        }
    }
}

// --- Main Execution ---
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Read input constraints
    if (!(cin >> N >> E >> C >> D >> lambda_val)) return 0;

    // 2. Read Power (P) and Interference (I) multipliers (1-indexed)
    P.assign(C + 1, 0);
    for (int i = 1; i <= C; ++i) cin >> P[i];

    I.assign(C + 1, 0);
    for (int i = 1; i <= C; ++i) cin >> I[i];

    // 3. Read all edges
    input_edges.resize(E);
    for (int i = 0; i < E; ++i) {
        cin >> input_edges[i].first >> input_edges[i].second;
    }

    current_colors.assign(N + 1, 0);

    // --- PHASE 1: Try with all edges intact ---
    int all_edges_mask = (1 << E) - 1; 
    build_graph(all_edges_mask);
    max_score = -2e18; // Reset max score
    
    solve(1); // Start Backtracking

    // If a valid configuration was found, print and exit
    if (max_score != -2e18) {
        cout << "VALID " << max_score << "\n";
        for (int i = 1; i <= N; ++i) {
            cout << best_colors[i] << (i == N ? "" : " ");
        }
        cout << "\n";
        return 0;
    }

    // --- PHASE 2: Fallback to finding minimum edge removals ---
    int min_removed = E; 

    // Loop from (11...10) down to 0
    for (int mask = (1 << E) - 2; mask >= 0; --mask) {
        int removed = E - __builtin_popcount(mask);
        
        // Optimization: Skip if we already found a valid graph by removing fewer edges
        if (removed >= min_removed) continue; 

        build_graph(mask);
        max_score = -2e18;
        solve(1);

        if (max_score != -2e18) {
            min_removed = removed;
        }
    }

    // Output the minimum edges that had to be removed
    cout << "REMOVE " << min_removed << "\n";
    
    return 0;
}