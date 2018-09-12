## 最长重复子串

longest repeative substring

解法：后缀树

https://www.geeksforgeeks.org/suffix-tree-application-3-longest-repeated-substring/

http://pythonexample.com/code/longest-repeated-substring-python/

``` python
import sys

s=sys.stdin.readlines()[0]

class Node:
    def __init__(self, val):
        self.val = val
        self.children = {}
        self.indexes = []
         
def method1(str):
    def insert(root, str, index, original_suffix, level=0):
        root.indexes.append(index)
        # update the result if find more than two child in a 
        # node and longer than the result now
        if(len(root.indexes) > 1 and maxLen[0] < level):
            maxLen[0] = level
            maxStr[0] = original_suffix[0:level]
        if not str:
            return None
 
        if(str[0] not in root.children):
            child = Node(str[0])
            root.children[str[0]] = child
        else:
            child = root.children[str[0]]
        insert(child, str[1:], index, original_suffix, level+1)
        return None
    maxLen = [0]
    maxStr = ['']
    root = Node('@')
    for i in range(len(str)):
        s = str[i:]
        insert(root, s, i, s)
    print maxStr[0],maxLen[0]

method1(s)
```