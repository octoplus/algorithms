
#include <bits/stdc++.h>

using namespace std;

int N = 20;

void insertion_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        int c = a[k];
        a[k] = a[i];
        a[i] = c;
    }
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
    memcpy(b, a, sizeof(a));
    insertion_sort(b, N);
    for (int i = 0; i < N; i++)
    {
        cout << b[i] << ",";
    }
    return 0;
}