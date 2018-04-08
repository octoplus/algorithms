#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int quickpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a = a * a;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    cout << quickpow(10, 3) << endl;
    return 0;
}