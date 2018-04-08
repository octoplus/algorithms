#include <bits/stdc++.h>

using namespace std;

void insert_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        int tmp = a[k];
        for (int j = k; j > i; j--)
        {
            a[j] = a[j - 1];
        }
        a[i] = tmp;
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
    insert_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}