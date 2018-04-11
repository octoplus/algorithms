#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int num = 0;
    bool x[n];
    memset(x, 0, sizeof(x));
    char c = s[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= c)
        {
            x[i] = true;
            num++;
            c = s[i];
        }
    }
    char ans[num + 1];
    memset(ans, '\0', sizeof(ans));
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i])
            ans[j++] = s[i];
    }
    cout << ans << endl;

    return 0;
}