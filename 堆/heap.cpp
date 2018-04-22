#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

int heap[MAX_SIZE];

int PARENT(int i)
{
    return floor(i);
}

int LEFT(int i)
{
    return 2 * i;
}

int RIGHT(int i)
{
    return 2 * i + 1;
}

void exchange(int i, int j){
    int tmp=heap[i];
    heap[i]=heap[j];
    heap[j]=tmp;
}

void max_heapify(int i, int heap_size)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;
    if (l <= heap_size && heap[l] > heap[i])
    {
        largest = l;
    }
    if (r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        exchange(i,largest);
        max_heapify(largest, heap_size);
    }
}

void build_max_heap(int heap_size)
{
    for (int i = floor(heap_size / 2); i >= 1; i--)
    {
        max_heapify(i, heap_size);
    }
}

void show_heap(int n){
    for (int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
}

void heap_sort(int heap_size)
{
    build_max_heap(heap_size);
    show_heap(heap_size);
    for (int i = heap_size; i >= 2; i--)
    {
        exchange(1,i);
        show_heap(heap_size);
        max_heapify(1, i-1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> heap[i];
    }
    heap_sort(n);

    for (int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }

    return 0;
}