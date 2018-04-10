#include <bits/stdc++.h>

using namespace std;

int color(int n, int m)
{
    int ans = 0;
    if (n == 1 && m >= 1)
        return m;
    if (n == 2 && m >= 2)
        return m * (m - 1);
    if (n == 3 && m >= 3)
        return m * (m - 1) * (m - 2);
    if (n > 3 && m >= 2)
        ans = color(n - 1, m) * (m - 2) + color(n - 2, m) * (m - 1);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << color(n, m) << endl;
    return 0;
}