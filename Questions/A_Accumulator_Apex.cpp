vector<int> ans(n);
    
    // 1. Initialize with fixed sizes instead of using .reserve()
    vector<int> act(n+1);
    vector<int> nxt(n+1);
    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        // 2. Track size manually instead of .clear() and .pb()
        int act_sz = 1;
        act[0] = i;
        vis[i] = i;

        while(1) {
            char mxc = -1;
            
            // 3. Loop using the size tracker
            for(int j = 0; j < act_sz; j++) {
                int u = act[j];
                for(auto &edge : adj[u]) {
                    char c = edge.first;
                    int v = edge.second;
                    if(vis[v] != i) {
                        if(c > mxc) {
                            mxc = c;
                        }
                        break;
                    }
                }
            }

            if(mxc == -1) break;

            // 4. Track next array size manually
            int nxt_sz = 0;
            for(int j = 0; j < act_sz; j++) {
                int u = act[j];
                for(auto &edge : adj[u]) {
                    char c = edge.first;
                    int v = edge.second;
                    if(vis[v] != i) {
                        if(c == mxc) {
                            vis[v] = i;
                            nxt[nxt_sz++] = v; // Replaces nxt.pb(v)
                        } else if(c < mxc) {
                            break;
                        }
                    }
                }
            }

            // 5. Replace act = move(nxt) with a manual copy
            act_sz = nxt_sz;
            for(int j = 0; j < act_sz; j++) {
                act[j] = nxt[j];
            }
        }

        // 6. Final loop using act_sz
        int bst = -1;
        for(int j = 0; j < act_sz; j++) {
            if(act[j] > bst) {
                bst = act[j];
            }
        }
        ans[i-1] = bst;
    }

    return ans;
}