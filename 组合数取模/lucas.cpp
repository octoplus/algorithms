#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

typedef long long LL;

//快速幂，但是这里需要取模
LL quick_pow(LL a, LL b)
{
    LL ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
            b--;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if (m > n)
        return 0;
    LL ans = 1;
    for (int i = 1; i <= m; i++)
    {
        LL a = (n + i - m) % mod;
        LL b = i % mod;
        //利用逆元求解组合数
        ans = ans * (a * quick_pow(b, mod - 2) % mod) % mod;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if (m == 0)
        return 1;
    return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}

/*
 其实这题不需要Lucas定理，因为题目说明了n，m的范围是100以内
 */
int main()
{
    int K;
    int A, X, B, Y;
    cin >> K >> A >> X >> B >> Y;
    LL result = 0;
    for (int i = 0; i <= X; i++)
    {
        for (int j = 0; j <= Y; j++)
        {
            if (A * i + B * j == K)
            {
                result = (result + (Lucas(X, i) * Lucas(Y, j)) % mod) % mod;
            }
        }
    }
    cout << result << endl;
    return 0;
}