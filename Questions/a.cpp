#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d1, d2, d3, d4;
    cin >> d1 >> d2 >> d3 >> d4;
    vector<int> a(8, 0);
    a[3] = d1;
    a[5] = d2;
    a[6] = d3;
    a[7] = d4;
    int p1 = a[3] + a[5] + a[7];
    a[1] = p1 % 2;
    int p2 = a[3] + a[6] + a[7];
    a[2] = p2 % 2;
    int p4 = a[5] + a[6] + a[7];
    a[4] = p4 % 2;
    cout << "Generated Hamming Code: ";
    for (int i = 1; i <= 7; ++i){
        cout << a[i];
    }
    cout << endl;
    int r1, r2, r3, r4, r5, r6, r7;
    cin >> r1 >> r2 >> r3 >> r4 >> r5 >> r6 >> r7;
    vector<int> r(8);
    r[1] = r1;
    r[2] = r2;
    r[3] = r3;
    r[4] = r4;
    r[5] = r5;
    r[6] = r6;
    r[7] = r7;
    int s1 = (r[1] + r[3] + r[5] + r[7]) % 2;
    int s2 = (r[2] + r[3] + r[6] + r[7]) % 2;
    int s3 = (r[4] + r[5] + r[6] + r[7]) % 2;
    int e = s1 * 1 + s2 * 2 + s3 * 4;
    if (e == 0){
        cout << "No Error Detected" << endl;
    }
    else{
        cout << "Error Detected at position: " << e << endl;
        r[e] = 1 - r[e];
        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= 7; ++i){
            cout << r[i];
        }
        cout << endl;
    }
    return 0;
}
