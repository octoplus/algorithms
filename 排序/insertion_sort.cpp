#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int a[], int n)
{
    int k;
    for (int j = 1; j < n; j++)
    {
        k = a[j];
        int i = j - 1;
        while (i > 0 and a[i] > k)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = k;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertion_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}