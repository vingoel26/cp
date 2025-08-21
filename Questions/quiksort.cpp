#include <bits/stdc++.h>
using namespace std;

int divide(vector<int> &a, int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[h];
    a[h] = temp;
    return i + 1;
}

void quicksort(vector<int> &a, int l, int h)
{
    if (l < h)
    {
        int pi = divide(a, l, h);
        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}