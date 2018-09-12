#include<bits/stdc++.h>

using namespace std;

void kmp_table(string &p,vector<int> &next){
    int m=p.size();
    int k=-1;
    for(int q=1;q<m;q++){
        while(k>=0 && p[k+1]!=p[q])
            k=next[k];
        if(p[k+1]==p[q])
            k++;
        next[q]=k;
    }
}

int LCPS(string &s, string &p){
    int n=s.size();
    int m=p.size();
    vector<int> next(m,-1);
    kmp_table(p,next);
    int q=-1;
    for(int j=1;j<n;j++){
        while(q>=0 && p[q+1]!=s[j])
            q=next[q];
        if(p[q+1]==s[j])
            q++;
        if(j!=n-1 && q==m-1)
            //与kmp不同
            q=next[q];
    }
    return q+1;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int res=max(LCPS(s1,s2),LCPS(s2,s1));
    cout<<res<<endl;
    return 0;
}