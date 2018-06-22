#include <bits/stdc++.h>

using namespace std;

vector<int> gen_next(string p)
{
    vector<int> next(p.size());
    return next;
}

int kmp(string p, string s)
{
    vector<int> next = gen_next(p);
    int i = 0;
    int n = s.size();
    int m = p.size();
    while (i <= n - m)
    {
        int j = 0;
        for (; j < m; j++)
        {
            if (p[j] != s[i + j])
            {
                i = i + next[j];
            }
        }
        if (j < m)
            continue;
        return i + j;
    }
    return 0;
}

int main()
{
    string s = "BBC ABCDAB ABCDABCDABDE";
    string p = "ABCDABD";
    cout << kmp(p, s) << endl;
    return 0;
}