#include<bits/stdc++.h>

using namespace std;

void kmp_table(string &p, vector<int>& next){
    int m=p.size();
    next[0]=-1; //第1位miss一定要从头匹配
    int pos=1;
    int cnd=0;
    while(pos<m){
        if(p[pos]==p[cnd]){
            next[pos]=next[cnd];
            pos++;
            cnd++;
        }else{
            next[pos]=cnd;
            cnd=next[cnd];
            while(cnd>=0 && p[pos]!=p[cnd])
                cnd=next[cnd];
            pos++;
            cnd++;
        }
    }
    next[pos]=cnd;
}

int kmp_search(string& s,string& p){
    int n=s.size();
    int m=p.size();
    vector<int> next(m+1,0);
    kmp_table(p,next);    
    // for(int i:next)
    //     cout<<i<<" ";
    // cout<<endl;
    
    int j=0;
    int k=0;

    while(j<n){
        if(s[j]==p[k]){
            j++;
            k++;
            if(k==m){
                return j-k;
            }
        }else{
            k=next[k];
            if(k<0){
                j++;
                k++;
            }
        }
    }
    return -1;

}