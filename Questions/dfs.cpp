#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> at(n), bt(n), rt(n), ct(n), wt(n), tat(n);
    for(int i = 0; i < n; i++) {
        cin >> at[i] >> bt[i];
        rt[i] = bt[i]; 
    }
    int count = 0, t = 0;
    while(count < n) {
        int idx = -1;
        int min_rt = 1000000000;
        for(int i = 0; i < n; i++) {
            if(at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }
        if(idx == -1) {
            t++;
            continue;
        }
        rt[idx]--;
        t++;
        if(rt[idx] == 0) {
            count++;
            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx]  = tat[idx] - bt[idx];
        }
    }
    cout << "SJF PREEMPTIVE"<<endl;
    cout << "P  AT  BT  CT  WT  TAT"<<endl;
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "  "<< at[i] << "  "<< bt[i] << "  "<< ct[i] << "  "<< wt[i] << "  "<< tat[i] << endl;
    }
    vector<int> ct2(n), wt2(n), tat2(n);
    vector<bool> vis(n,false);
    int count1 = 0;
    t = 0;
    while(count1 < n) {
        int idx = -1;
        int min_bt = 1000000000;
        for(int i = 0; i < n; i++) {
            if(at[i] <= t && !vis[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }
        if(idx == -1) {
            t++;
            continue;
        }
        t += bt[idx];
        ct2[idx] = t;
        tat2[idx] = ct2[idx] - at[idx];
        wt2[idx] = tat2[idx] - bt[idx];
        vis[idx] = true;
        count1++;
    }
    cout <<"SJF NON-PREEMPTIVE"<<endl;
    cout << "P  AT  BT  CT  WT  TAT"<<endl;
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "  "<< at[i] << "  "<< bt[i] << "  "<< ct2[i] << "  "<< wt2[i] << "  "<< tat2[i] << endl;
    }
    return 0;
}
