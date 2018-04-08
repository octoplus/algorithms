#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C, n; // 背包总容量 物品数量
    cin >> C >> n;
    // 0号位置闲置
    int w[n + 1]; // 物品重量
    int v[n + 1]; // 物品价值
    int x[n + 1]; // 是否选择某一物品

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // 定义dp数组，设置一定的冗余
    int f[n + 5][C + 5];

    // 将数组初始化为0
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (w[i] > j) // i号物品重量大于当前背包容量
                f[i][j] = f[i - 1][j];
            else
            {
                /* 
                i号物品重量小于等于当前背包容量
                或者放入i，或者不放入i
                两种情况对应的最优解取最大值
                */
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    // 恢复出最优解选择的物品
    for (int i = n, c = C; i > 0; i--)
    {
        // 如果i物品考察与否不影响结果，则i物品没有被选择
        if (f[i][c] == f[i - 1][c])
            x[i] = 0;
        else
        {
            x[i] = 1;
            c -= w[i];
        }
    }

    // 输出最优解
    cout << f[n][C] << endl;

    for (int i = 1; i <= n; i++)
    {
        if (x[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}