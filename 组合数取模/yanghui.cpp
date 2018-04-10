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
    int C[n + 1][m + 1];
    C[0][0] = 1;
    cout << C[0][0] << endl;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
        cout << C[i][0] << " ";
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            cout << C[i][j] << " ";
        }
        C[i][i] = 1;
        cout << C[i][i];
        cout << endl;
    }
    return 0;
}