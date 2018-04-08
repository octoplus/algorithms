#include <bits/stdc++.h>

using namespace std;

int N = 20;

void merge(int a[], int l, int m, int r, int tmp[])
{
    int i = l, j = m + 1;
    int num = l;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[num] = a[i];
            num++;
            i++;
        }
        else
        {
            tmp[num] = a[j];
            num++;
            j++;
        }
    }
    while (i <= m)
    {
        tmp[num] = a[i];
        num++;
        i++;
    }
    while (j <= r)
    {
        tmp[num] = a[j];
        num++;
        j++;
    }
    memcpy(a + l, tmp + l, (r - l + 1) * sizeof(int));
}

void merge_sort(int a[], int l, int r, int tmp[])
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(a, l, m, tmp);
    merge_sort(a, m + 1, r, tmp);
    merge(a, l, m, r, tmp);
}

int main()
{
    int a[N];
    int b[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << ",";
    }
    cout << endl;
    merge_sort(a, 0, N - 1, b);
    for (int i = 0; i < N; i++)
    {
        cout << b[i] << ",";
    }
    return 0;
}