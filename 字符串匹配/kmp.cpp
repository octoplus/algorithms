#include <bits/stdc++.h>

using namespace std;

void kmp_table(string &p,vector<int> &next){
    int m=p.size();
    next[0]=-1;
    int k=-1;
    int q;
    for(q=1;q<m;q++){
        while(k>=0 && p[k+1]!=p[q])
            k=next[k];
        if(p[k+1]==p[q])
            k++;
        next[q]=k;
    }
}

int kmp(string&s,string&p){
    int n=s.size();
    int m=p.size();
    vector<int> next(m,-1);
    kmp_table(p,next);
    int q=-1;
    for(int j=0;j<n;j++){
        while(q>=0 && p[q+1]!=s[j])
            q=next[q];
        if(p[q+1]==s[j])
            q++;
        if(q==m-1)
            return j-m+1;
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