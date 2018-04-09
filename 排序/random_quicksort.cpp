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

int random_partion(int a[], int l, int r)
{
    int i = rand() % (r - l) + l;
    int tmp = a[r];
    a[r] = a[i];
    a[i] = tmp;
    return partion(a, l, r);
}

void random_quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int q = random_partion(a, l, r);
        random_quicksort(a, l, q - 1);
        random_quicksort(a, q + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    random_quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}