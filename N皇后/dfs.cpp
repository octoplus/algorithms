#include<bits/stdc++.h>

using namespace std;

/**
 * 不仅是不能同行同列，同斜对角也不行
 * 深度优先的入门经典题
 */


vector<vector<string> > res;

void dfs(int n, int d,vector<string> path,int mid,int left,int right){
    for(int i=0;i<n;i++){
        int flag=1<<i;
        if(((mid |left|right) & flag) ==0) {
            string tmp=string(n,'.');
            tmp[i]='Q';
            vector<string> tmp_path(path);
            tmp_path.push_back(tmp);
            if(d==n)      
                res.push_back(tmp_path);
            else{
                dfs(n,d+1,tmp_path,(mid |flag),(left|flag)<<1,(right|flag)>>1);
            }
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    dfs(n,1,vector<string>(),0,0,0);
    return res;
}

int main(){
    auto res=solveNQueens(4);
    cout<<res.size()<<endl;
    for(auto v:res){
        for(auto s:v){
            cout<<s<<endl;
        }
        cout<<endl;
    }
    return 0;
}