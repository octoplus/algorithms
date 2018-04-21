#include <bits/stdc++.h>

using namespace std;

int A[100005];

int GCD(int a, int b)
{
    return a % b ? GCD(b, a % b) : b;
}

int main()
{
    int N, n, m, p;
    cin >> N >> n >> m >> p;
    int i = 1;
    A[i] = p;
    i++;
    while (i <= N)
    {
        A[i] = (A[i - 1] + 153) % p;
        i++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp=GCD(i, j);
            // cout<<i<<" "<<j<<" " <<tmp<<endl;
            ans += A[tmp];
        }
    }
    cout << ans << endl;

    return 0;
}