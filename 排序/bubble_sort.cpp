#include <bits/stdc++.h>

using namespace std;

int N = 20;

void bubble_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    bubble_sort(a,N);
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}