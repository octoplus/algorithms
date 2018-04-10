#include <bits/stdc++.h>

using namespace std;

#define MAXL 200

int dp[MAXL][MAXL];

int PSC(string s)
{
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    for (int j = 0; j < n; j++)
    {
        dp[j][j] = 1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << PSC(s) << endl;
    return 0;
}