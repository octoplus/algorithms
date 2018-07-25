## 单调栈

顾名思义，单调栈就是栈内的值是单调递增或者递减的。这是一类方法的统称，在求解最大求和子数组、最大求和子矩阵这类问题的时候比较通用的套路解法。自己初次接触是在某次LeetCode contest中，就是下面介绍的“求和大于K的最短子数组”

### 求和大于K的最短子数组
LeetCode 862题：https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

虽然这类问题有一个套路，一般需要对原数组求一个累和，然后就可以求任意起始和结束位置的子数组求和大小

但是当时做的时候没有思路

看了别人的解法之后，里面使用的双端队列deque，让我感觉很巧妙，这里那位同学其实就是用了单调栈（实现单调栈的数据结构不是很重要，可以用普通的数组或者vector来实现相同的功能），具体解法请查看`subarray_sum_at_least_k.cpp`

### 求和最大子数组
LeetCode 53题：https://leetcode.com/problems/maximum-subarray/description/

给定一个数组，求解子数组求和最大的结果，单调栈最基本的应用，这个问题并不一定需要用单调栈来解，但是用单调栈求解一样可以达到O(n)的复杂度。具体可以查看`max_subarray.cpp`

### 柱状图中最大的子矩形
LeetCode 84题：https://leetcode.com/problems/largest-rectangle-in-histogram/description/

详细的解释可以看：https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

### 求和最大1子矩阵（LeetCode，矩阵由0、1组成）
LeetCode 85题：https://leetcode.com/problems/maximal-rectangle/description/

这一题可以转换成上一题，然后用上一题的O(n)时间的算法进行求解，最后总的复杂度是O(n^2)

### 求和最大子矩阵（牛客，矩阵由任意整数组成）
这题是在牛客上无意间刷到的，也正是遇到了这一题，让我想起来总结“单调栈”这一类问题

题目网址：https://www.nowcoder.com/acm/contest/131/B


### 总结
从上面这些题目可以看到，大部分时候是将一个较为复杂的问题简化到一维数组的问题，然后用单调栈求解；有时候一维数组问题还会带一些限制，所以要在单调栈上做一些改进，但基本思想还是维护一个单调栈。