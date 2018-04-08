#include <bits/stdc++.h>

using namespace std;

/*
 可以利用杨辉三角形求范围较小的组合数
 该程序只打印n行的杨辉三角形
 */

int main()
{
    int n;
    cin >> n;
    int m = n + 2;
    int f[n + 1][m + 1];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = 1;
        cout << f[i][0] << " ";
        for (int j = 1; j < i; j++)
        {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            cout << f[i][j] << " ";
        }
        f[i][i] = 1;
        cout << f[i][i];
        cout << endl;
    }
    return 0;
}