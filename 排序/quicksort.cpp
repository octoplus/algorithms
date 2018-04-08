#include <bits/stdc++.h>

using namespace std;

int partion(int a[], int low, int high)
{
    int i = low - 1;
    int k = a[high];
    /* 
    i从虚无中来
    i所到之地，即为k征服之地
    霸业已成，i与k毗邻
    */
    for (int j = low; j < high; j++)
    {
        if (a[j] <= k)
        {
            i++;
            if (i != j)
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    a[high] = a[i + 1];
    a[i + 1] = k;
    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int k = partion(a, low, high);
    quicksort(a, low, k - 1);
    quicksort(a, k + 1, high);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // int n = 10;
    // int a[] = {7, 49, 73, 58, 30, 72, 44, 78, 23, 9};
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}