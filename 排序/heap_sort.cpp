#include <bits/stdc++.h>

using namespace std;

int N = 20;

void heap_sort(int a[], int n)
{
    priority_queue<int, vector<int>, greater<int> > q; //最小堆，从小到大排序
    //priority_queue<int> q; //默认大根
    for (int i = 0; i < n; i++)
    {
        q.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = q.top();
        q.pop();
    }
}

int main()
{
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    heap_sort(a, N);
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}