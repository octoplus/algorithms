#include <bits/stdc++.h>

using namespace std;

#define MAXL 200

int dp[MAXL][MAXL];

string recover(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    int l = dp[n][m];

    char ans[l + 1];
    memset(ans, '\0', sizeof(ans));
    int i=n,j=m;
    while(i>0 &&j>0){
        while(i>0 && dp[i][j]==dp[i-1][j])
            i--;
        while(j>0 && dp[i][j]==dp[i][j-1])
            j--;
        if(i>0 &&j>0){
            int k=dp[i][j];
            ans[k-1]=s1[i-1];
        }
        i--;
        j--;
    }
    return ans;
}

int LCS(string s1, string s2)
{
    memset(dp,0,sizeof(dp));
    int n = s1.size();
    int m = s2.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
    cout << recover(s1, s2) << endl;
    return 0;
}