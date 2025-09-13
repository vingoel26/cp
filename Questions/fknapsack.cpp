#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int k;
    cin>>k;
    vector<vector<int>> c(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        c[i][0] = a[i];
        c[i][1] = b[i];
    }
    sort(c.begin(), c.end(), comp);
    double res = 0.0;
    int k1 = k;
    for (int i = 0; i < n; i++) {
        if (c[i][1] <= k1) {
            res += c[i][0];
            k1 -= c[i][1];
        }
        else {
            res += (1.0 * c[i][0] / c[i][1]) * k1;
            break; 
        }
    }
    cout<<res<<endl;
    return 0;
}