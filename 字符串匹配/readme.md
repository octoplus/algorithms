## 字符串匹配

问题描述，给定一个字符串s（目标串）和另一个字符串p（模式串），求s中是否包含p

设s的长度为n，p的长度为m

各种算法的复杂度对比：

算法|预处理时间|匹配时间
-|-|-
朴素|0|O((n-m+1)*m)
KMP|O(m)|O(n)

代码练习：LeetCode28题，自己实现的代码可以在oj上测试一下

### 朴素

最直接的方法就是将s的每个位置作为起始，然后逐个字符与p比较，复杂度为O(n*m)

### KMP

Knuth-Morris-Pratt算法（简称KMP）是以三个发明者的名字命名的算法

kmp的核心思想，是尽量利用之前的对比结果。

方法是是观察模式串，模式串（p串）的偏后的位置可能与前面的位置重复，这种情况下，匹配到后面的重复部分，但最终失败了，就不需要从p串的最开始重新匹配，而是跳过s串中看过的字符（注意，这是精髓所在，s串中观察的位置不会变，移动的是p串，所以匹配阶段的复杂度是O(n)）。

kmp算法用一个next数组来存储观察的结果，并决定出现miss的时候p串移动多少位

移动位数 = 已匹配的字符数 - 表格内的匹配值 （辅助理解）

其实移动位数是没用的，所谓移动不过是设置p串比较开始的位置，next数组/字典里存了miss位置相应的下次重启匹配的位置

网上有一些不同版本的实现，有一些存在问题。我觉得讲的比较透彻的还是要看算法导论


#### clrs版本（算法导论）

代码在clrs.cc中

kmp分成构建next数组、匹配两个步骤，两个步骤的代码非常相似，因为构建next数组的过程可以理解为用p串匹配自身

其中最难理解的部分就是构建next数组的部分

首先要理解next[i]的含义：
1）Pi（p串从0到i的子串）最长的 前缀=后缀
2）i这个位置匹配后，能确保不用再看一遍的前缀长度，结合1）理解
3）如果i+1位匹配失败，就要看i位的next值

再看构建next部分的代码
``` cpp
void kmp_table(string &p,vector<int> &next){
    int m=p.size();
    next[0]=-1;
    int k=-1;
    int q;
    for(q=1;q<m;q++){
        while(k>=0 && p[k+1]!=p[q])
            k=next[k];
        if(p[k+1]==p[q])
            k++;
        next[q]=k;
    }
}
```

```
       i
|···XXXx···|
   |XXXy·····|
      k

```
XXX表示已经匹配的部分，x、y表示不匹配的第一个字符，i表示现在主循环遍历到的位置，k表示匹配到的最长前缀位置

根据代码这时候就会执行k=next[k]，为什么呢？（我个人的感觉就像是递归）因为位置i-1至少匹配了长度为k+1的模式前缀，但是y与x又miss了，只能把模式串往后移，这时候就要找到XXX中，前缀=后缀的最大位置，这样x之前的位置又是匹配的了，但是显然XXX（即已匹配的区段）变短了，至少减少1。

比如p=aabaaa

```
   i
|aab···|
 |aa·····|
  k
```
比如这种情况下XXX="a"，但第一个位置的next被赋成了-1

```
      i
|aabaaa|
   |aab····|
     k
```
比如这种情况下XXX="aa"，因为a、b不匹配，模式串要右移，那么k所在的位置即a也不能使用，但是“真”前缀（就是长度小于原串）能用。"aa"的前缀=后缀，就是k=0，就变成了如下形式，发现i与k+1位匹配，继续往后匹配

```
      i
|aabaaa|
    |aa·····|
     k
```
这就是内层while循环所做的工作，一直改动k，来获取能用的最大前缀=后缀

#### 网络上的实现

参考网址1：https://www.cnblogs.com/yusenwu/p/4782043.html

反例：s=aabaaabaaac，p=aabaaac，当最后的c那一位miss的时候，就会出错


geekforgeek版本，代码和注释在文件gfg.cc中

参考网址2：https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

wikipedia版本，代码和注释在文件wikipedia.cc

参考网址3：https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

理解误区，开始我以为wiki上的版本和clrs上的kmp的next数组含义是一样的，但计算一些pattern的结果之后发现两者不相同，策略也不同，比如

 a a a a  

-1 0 1 2 #因为是重复的，所以这一位匹配不到，就可以从前一位重新开始  

但是算法的结果  
 a  a  a  a  
-1 -1 -1 -1  

这让我以为算法的实现是有问题的，但是思考之后发现，如果是aaaa这种情况，当前位匹配不到，那说明s串当前为肯定不是a，所以应该直接跳到p串的起始位置重新匹配

一些next计算结果
aaaa
-1 -1 -1 -1
baaa
-1 0 0 0
abaa
-1 0 -1 1
aabaaac
-1 -1 1 -1 -1 2 2

### 最长前后重叠子串

问题描述：给定两个字符串s1、s2，求s1与s2首尾重叠最长是多少，即求最长的s1的后缀=s2的前缀，或者s1的前缀=s2的后缀。（电信笔试）

#### 暴力解法
固定重叠子串长度，验证是否满足，如果满足增加长度，继续验证，直到不满足

暴力解法的复杂度是O(n*m)

#### kmp

用kmp的思想，next数组会包含匹配失败位置的最长前后缀。先用s1当做模式串，构造next数组，去匹配s2，在s2返回的k就是最长的重叠前后缀；s2当做模式串进行相同的操作，选取两次结果较大的。复杂度O(max{m,n}}

代码文件lcps.cc(longest common prefix sufix)

### 最长重复子串

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

