class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> val(bank.begin(), bank.end());
        if (val.find(endGene) == val.end()) return -1;
        queue<string> q;
        q.push(startGene);
        int ct = 0;
        char dir[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string u = q.front();
                q.pop();
                if (u == endGene) return ct;
                for (int i = 0; i < u.size(); i++) {
                    char original = u[i];
                    for (char a : dir) {
                        u[i] = a;
                        if (val.count(u)) {
                            q.push(u);
                            val.erase(u);
                        }
                    }
                    u[i] = original;
                }
            }
            ct++;
        }
        return -1;
    }
};