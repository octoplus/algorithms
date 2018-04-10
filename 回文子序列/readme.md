## 回文子序列

区别“子串”，“子序列”不需要连续  

“pal”，“dromi”是“palindromic”的子串

“pldm”是“palindromic”的子序列，而“lpd”不是

## 最长公共子序列

Longest Common Sequence (LCS)

**动态规划**

子问题划分：  

dp[n+1][m+1]

dp[i][j]表示s1[0,i-1]和s2[0,j-1]的最长公共子序列长度 1<=i<=n 1<=j<=m
```
if s1[i-1]==s2[j-1] dp[i][j] = dp[i-1][j-1]+1  

if s1[i-1]!=s2[j-1] dp[i][j] = max{dp[i-1][j],dp[i][j-1]}
```

恢复

```
s1: ajjdsdcd
s2: jjwecda

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1
0 1 1 1 1 1 1 1
0 1 2 2 2 2 2 2
0 1 2 2 2 2 3 3
0 1 2 2 2 2 3 3
0 1 2 2 2 2 3 3
0 1 2 2 2 3 3 3
0 1 2 2 2 3 4 4
```
从dp[n][m]开始，走到对上对左都大的位置，输出对应位置的字母，然后i、j同时减一，重复过程

## 最长回文子序列

Longest Palindromic Sequence (LPS)

“abcdfcba”的最长回文子序列长度是7

**动态规划**

子问题划分：  
dp[i][j]表示s从i开始到j的子串的最长回文子序列有多长

if s[i]==s[j]: dp[i][j]=dp[i+1][j-1]+2  
子串的头尾相同，则最长回文子串为去掉头尾+2

if s[i]!=s[j]: dp[i][j]=max{dp[i+1][j],dp[i][j-1]}

**LCS**
将字符串反序，与原字符串做LCS，就可以得到LPS

## 回文子序列个数

Palindromic Sequence Count (PSC)

位置不同、内容相同的回文子序列算不同的子序列

**动态规划**

子问题划分：  
dp[i][j]表示s从i开始到j的子串的回文子序列有多少个

初始状态：  
dp[i][i]=1 

if s[i]==s[j]: dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1  
子串头尾相同  
A：同时包含i，j的回文子序列个数，就是D+1，因为D中任何一种回文配上ij都成为一种新回文，且只有i,j也是一种方案，所以是D+1  
B：包含i，但不包含j，就是dp[i][j-1]-D  
C：包含j，但不包含i，就是dp[i+1][j]-D  
D：不包含i，也不包含j，就是dp[i+1][j-1]  
dp[i][j]=A+B+C+D= D+1 + dp[i][j-1]-D + dp[i+1][j]-D + D=dp[i+1][j] + dp[i][j-1] + 1


if s[i]!=s[j]: dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]  
头尾不同  
B：包含i，但不包含j，就是dp[i][j-1]-D  
C：包含j，但不包含i，就是dp[i+1][j]-D  
D：不包含i，也不包含j，就是dp[i+1][j-1]  
dp[i][j]=B+C+D=dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]