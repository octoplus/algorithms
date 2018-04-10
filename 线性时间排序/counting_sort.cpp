#include <bits/stdc++.h>

using namespace std;

void counting_sort(int a[], int n, int k)
{
    int b[n];
    int c[k];
    memcpy(b, a, sizeof(int) * n);
    memset(c, 0, sizeof(int) * k);
    for (int i = 0; i < n; i++)
    {
        c[b[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        c[i] += c[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // 注意下标要减一
        a[c[b[i]]-1] = b[i];
        c[b[i]]--;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    counting_sort(a, n, 100);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}