#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

/**
 * 原来的思路是4层for循环，有的case超时了
 * 后来实在想不到，就查看了别人的解法，是用来“单调栈/单调队列”
 * 这样复杂度就从O(n^4)降到了O(n^3)
 */

int R, C, X, Y, Z;
int a[505][505];
LL s[505][505];
int z[505][505];
LL sx[505];
LL zx[505];

int main()
{
    cin >> R >> C >> X >> Y >> Z;
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    memset(z, 0, sizeof(z));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i][j - 1] + a[i][j];
            z[i][j] = z[i][j - 1] + (a[i][j] == 0);
        }
    }
    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         cout<<s[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         cout<<z[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    LL res = 0;
    for (int j = 1; j <= C; j++)
    {
        int y_min = max(0, j - Y);
        for (int ys = j - 1; ys >= y_min; ys--)
        {
            deque<int> dq;
            LL tmp_sum = 0;
            LL tmp_z = 0;
            sx[0] = 0;
            zx[0] = 0;
            dq.push_back(0);
            // cout<<ys<<","<<j<<endl;
            for (int i = 1; i <= R; i++)
            {
                tmp_sum += s[i][j] - s[i][ys];
                tmp_z += z[i][j] - z[i][ys];
                sx[i] = tmp_sum;
                zx[i] = tmp_z;
                // cout<<tmp_sum<<",";
                while (!dq.empty() && sx[dq.back()] > tmp_sum)
                    dq.pop_back();
                while (!dq.empty() && tmp_z - zx[dq.front()] > Z)
                    dq.pop_front();
                while (!dq.empty() && i - dq.front() > X)
                    dq.pop_front();
                dq.push_back(i);
                res = max(res, tmp_sum - sx[dq.front()]);
            }
            // cout<<endl;
            // for(int i=1;i<=R;i++)
            //     cout<<zx[i]<<",";
            // cout<<endl;
            // cout<<res<<endl;
            // cout<<endl;
        }
    }
    cout << res << endl;
    return 0;
}