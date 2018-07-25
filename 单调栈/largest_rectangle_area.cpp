#include <bits/stdc++.h>

using namespace std;

/**
 * 也是用了单调递增的栈
 * 当遇到一个比栈顶小的高度，设下标为i，设栈顶下标为tp，此时栈顶需要出栈
 * 此时可以推断出，栈中新的栈顶之后的下标直到tp，高度都是大于下标为tp的高度的
 * 而从tp开始，到现在遇到的i，高度也都比tp的高度大，否则tp早就出栈了
 */

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int ans = 0;
    int idx;
    int h;
    for (int i = 0; i <= n; i++)
    {
        h = (i == n ? 0 : heights[i]);
        if (s.empty() || h >= heights[s.top()])
            s.push(i);
        else
        {
            idx = s.top();
            s.pop();
            ans = max(ans, heights[idx] * (s.empty() ? i : i - s.top() - 1));
            i--;//如果发生了出栈，则需要在下一轮迭代继续与栈顶进行对比
        }
    }
    return ans;
}

int main()
{
    vector<int> v{2,1,5,6,2,3};
    cout<<largestRectangleArea(v)<<endl;
    return 0;
}