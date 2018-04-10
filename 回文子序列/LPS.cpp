#include <bits/stdc++.h>

using namespace std;

#define MAXL 200

int dp[MAXL][MAXL];

string recover(string s)
{
    int n = s.size();
    // 恢复最长回文子序列
    int l = dp[0][n - 1];
    char lps[l + 1];
    memset(lps, '\0', sizeof(lps));
    int i = 0, j = n - 1;
    while (i <= j)
    {
        while (i <= j && dp[i][j] == dp[i][j - 1])
            j--;
        while (i <= j && dp[i][j] == dp[i + 1][j])
            i++;
        if (i <= j)
        {
            int k = (l - dp[i][j]) / 2;
            lps[k] = lps[l - 1 - k] = s[i];
            i++;
        }
    }
    return lps;
}

int LPS(string s)
{
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    //注意 i j 顺序
    for (int j = 0; j < n; j++)
    {
        dp[j][j] = 1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << LPS(s) << endl;
    cout << recover(s) << endl;

    return 0;
}