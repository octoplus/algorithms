#include <bits/stdc++.h>

using namespace std;

int shortestSubarray(vector<int> &A, int K)
{
    int n = A.size();
    int B[n + 1]; //累和
    memset(B, 0, sizeof(B));
    for (int i = 0; i < n; i++)
        B[i + 1] = A[i] + B[i];
    deque<int> d;
    int ans = n + 1;
    for (int i = 0; i <= n; i++) //注意这里是对B进行遍历，个数是n+1
    {
        while (d.size() > 0 && B[i] - B[d.front()] >= K)
        {
            //这里默认B是单调递增的
            //为什么B要单调递增？因为如果更小的值出现在偏后的位置，就可以用更短的长度来达到更大的累和
            //比如A是 [2,-1,2,1]
            //对应B就是[0,2,1,3,4]
            //下标1的值是2，下标2的值是1，下标3的值是3，1~3的累和是1，2~3的累和是2
            //所以只要前面的累和大于后面的累和，说明有负值存在，应该直接跳过从负值起步的累和
            ans = min(ans, i - d.front());
            d.pop_front();
        }
        while (d.size() > 0 && B[i] <= B[d.back()]) //为了保持B单调递增
            d.pop_back();
        d.push_back(i);
    }
    return ans <= n ? ans : -1;
}

int main()
{
    vector<int> v{2, -1, 2};
    cout << shortestSubarray(v, 3) << endl;
    return 0;
}