#include <bits/stdc++.h>
using namespace std;

void getFirstNumbers(vector<int> arr, int n) {
    int pata = 1;
    while (pata <= n) {
        cout << arr[pata - 1] <<endl;
        pata=pata+pata;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    getFirstNumbers(arr, n);
    return 0;
}
