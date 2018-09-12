#include <bits/stdc++.h>

using namespace std;

vector<int> gen_next(string p)
{
    int m=p.size();
    vector<int> next(m+1,0);
    int i=1;
    int pi=0;
    while(i<m){
        if(p[i]==p[pi]){
            pi++;
        }else{
            pi=next[pi];
        }
        next[i+1]=pi;
        i++;
    }
    return next;
}

int kmp(string s, string p) //如果s串中存在p串，则返回p串第一次匹配的地方
{
    vector<int> next = gen_next(p);
    // for(int k : next)
    //     cout<<k<<" ";
    // cout<<endl;
    int i = 0;
    int pi=0;
    int n = s.size();
    int m = p.size();
    while (i < n)
    {
        if(s[i]!=p[pi]){
            pi=next[pi];
        }
        if(s[i]==p[pi]) 
        /* 注意这里不能与上面那个判断合并，而且顺序不能换
           因为上面那个判断有可能改变pi的值
           正是这一判断分离可以让p串游标移动的同时，s串游标不动
         */
            pi++;
        if(pi==m)
            return i-m+1;
        i++;
    }
    return -1;
}

int main()
{
    string s = "aabaaabaaac";
    string p = "aabaaac";
    cout << kmp(s,p) << endl;
    return 0;
}