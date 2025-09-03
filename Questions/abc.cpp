#include <bits/stdc++.h>
using namespace std;
struct InputData {
    vector<pair<int,int>> connections;
    map<int,int> costs;
    map<int,int> values;
    int budget;
    int depth;
    vector<int> seed_order;
};
InputData readInput() {
    InputData d;
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        d.connections.push_back({u,v});
    }
    int ns;
    cin >> ns;
    for (int i = 0; i < ns; ++i) {
        int id,c;
        cin >> id >> c;
        d.costs[id] = c;
        d.seed_order.push_back(id);
    }
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        d.values[i] = val;
    }
    cin >> d.budget;
    cin >> d.depth;
    return d;
}
tuple<vector<int>, int, int> solveCampaign(const vector<pair<int,int>>& connections,
                                           const map<int,int>& costs,
                                           const map<int,int>& values,
                                           const vector<int>& seed_order,
                                           int budget, int dd) {
    unordered_map<int, vector<int>> g;
    for (auto &p : connections) {
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
    unordered_map<int,int> ord;
    for (int i = 0; i < (int)seed_order.size(); ++i) ord[seed_order[i]] = i;
    unordered_set<int> reached;
    unordered_set<int> chosen_set;
    vector<int> chosen;
    int total_val = 0;
    int total_cost = 0;
    int rem = budget;
    while (true) {
        double best_eff = -1.0;
        int best_id = -1;
        int best_gain = 0;
        vector<int> best_new;
        for (auto &pr : costs) {
            int id = pr.first;
            if (chosen_set.count(id)) continue;
            int c = pr.second;
            if (c > rem) continue;
            queue<pair<int,int>> q;
            unordered_set<int> seen;
            q.push({id,0});
            seen.insert(id);
            int gain = 0;
            vector<int> newn;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                int u = cur.first;
                int dep = cur.second;
                if (!reached.count(u)) {
                    auto it = values.find(u);
                    if (it != values.end()) {
                        gain += it->second;
                        newn.push_back(u);
                    }
                }
                if (dep == dd) continue;
                for (int v : g[u]) if (!seen.count(v)) {
                    seen.insert(v);
                    q.push({v, dep+1});
                }
            }
            double eff;
            if (c == 0) eff = gain > 0 ? 1e18 : 0.0;
            else eff = (double)gain / (double)c;
            if (eff > best_eff + 1e-12) {
                best_eff = eff;
                best_id = id;
                best_gain = gain;
                best_new = newn;
            } else if (fabs(eff - best_eff) <= 1e-12) {
                int a = ord.count(id) ? ord[id] : INT_MAX;
                int b = ord.count(best_id) ? ord[best_id] : INT_MAX;
                if (a < b) {
                    best_id = id;
                    best_gain = gain;
                    best_new = newn;
                }
            }
        }
        if (best_id == -1) break;
        if (best_gain <= 0) break;
        chosen.push_back(best_id);
        chosen_set.insert(best_id);
        total_cost += costs.at(best_id);
        rem -= costs.at(best_id);
        for (int x : best_new) {
            if (!reached.count(x)) {
                reached.insert(x);
                total_val += values.at(x);
            }
        }
    }
    return {chosen, total_val, total_cost};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputData data = readInput();
    auto res = solveCampaign(data.connections, data.costs, data.values, data.seed_order, data.budget, data.depth);
    vector<int> sel = get<0>(res);
    int tv = get<1>(res);
    int tc = get<2>(res);
    for (int i = 0; i < (int)sel.size(); ++i) {
        if (i) cout << " ";
        cout << sel[i];
    }
    cout << "\n";
    cout << tv << "\n";
    cout << tc << "\n";
    return 0;
}