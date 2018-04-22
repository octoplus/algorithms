## 堆
二叉堆是一个数组，它可以被看成一个近似的完全二叉树。

## 父节点、左节点、右节点

``` python
def parent(i):
    return int(i/2)

def left(i):
    return 2*i

def right(i):
    return 2*i+1
```

## 维护堆的性质

递归维护最大堆的性质

``` python
def max_heapify(A, i):
    l=left(i)
    r=right(i)
    if l<= A.heap-size and A[l]>A[i]:
        largest=l
    else
        largest=r
    if r<= A.heap-size and A[r]>A[largest]:
        largest=r
    if largest != i:
        exchange A[i] with A[largest]
        max_heapify(A,largest)
```

## 建堆

``` python
def build_max_heap(A):
    A.heap-size=A.length
    for i= floor(A.length/2) downto 1
        max_heapify(A,i)
```

## 堆排序

``` python
def heap_sort(A):
    build_max_heap(A)
    for i=A.length downto 2
        exchange A[1] with A[i]
        A.heap-size-=1
        max_heapify(A,1)
```