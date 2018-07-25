#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sum(n + 1, 0);
    deque<int> dq;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + nums[i];
        ans = max(ans, nums[i]);
    }
    for (int i : sum)
    {
        while (!dq.empty() && i < dq.back())
            dq.pop_back();
        if (!dq.empty())
            ans = max(ans, i - dq.front());
        dq.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> v1{-1};
    vector<int> v2{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(v2) << endl;
    return 0;
}