#include<bits/stdc++.h>

using namespace std;

vector<int> compute_prefix(string p){
    int m=p.size();
    vector<int> next(m,-1);
    int k=-1;
    int q;
    for(q=1;q<m;q++){
        while(k>=0 && p[k+1]!=p[q]){
            // 为什么k+1位不匹配后，要用next[k]来替代k呢？
            // 因为到目前位置前缀k都是匹配的，而next[k]存储的就是最长的前缀=后缀
            k=next[k];
        }
        if(p[k+1]==p[q])
            k++;
        next[q]=k;
    }
    
    // for(int i=0;i<m;i++){
    //     cout<<p[i]<<"\t";
    // }
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //     cout<<next[i]<<"\t";
    // }  
    // cout<<endl;
    return next;
}

int kmp_matcher(string &s,string &p){
    int n=s.size();
    int m=p.size();
    vector<int> next=compute_prefix(p);
    // q表示从p串开始已经匹配到的位置，最开始一个字符都没有，所以是-1
    // next表中记录的也是在相应为miss后，恢复到哪个q
    int q=-1; 
    for(int i=0;i<n;i++){
        while(q>=0 && p[q+1]!=s[i])
            q=next[q];
        if(p[q+1]==s[i])
            q++;
        if(q==m-1)
            return i-m+1;
    }
    return -1;
}

int main(){
    // string s = "aabaaabaaac";
    // string s = "aaabaaac";
    // string p = "aabaaac";
    string p;
    cin>>p;
    compute_prefix(p);
    // cout<<kmp_matcher(s,p)<<endl;
    return 0;
}