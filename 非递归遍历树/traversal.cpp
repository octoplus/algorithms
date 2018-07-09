#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};

void do_something(TreeNode *root){
    cout<<root->val<<",";
}

void recursive_preorder(TreeNode *root){
    if(root==NULL)
        return;
    do_something(root);
    recursive_preorder(root->left);
    recursive_preorder(root->right);
}

void recursive_inorder(TreeNode *root){
    if(root==NULL)
        return;
    recursive_inorder(root->left);
    do_something(root);
    recursive_inorder(root->right);
}

void recursive_postorder(TreeNode *root){
    if(root==NULL)
        return;
    recursive_postorder(root->left);
    recursive_postorder(root->right);
    do_something(root);
}

void preorder(TreeNode *root){
    stack<TreeNode*> stk;
    TreeNode* p=root;
    while(p!=NULL || !stk.empty()){
        while(p!=NULL){
            do_something(p); //先序直接处理
            stk.push(p); //遍历过的节点要压入栈，出栈的时候就访问它的右子树
            p=p->left; //只要左子树存在，一直先处理左子树
        }
        if(!stk.empty()){
            p=stk.top()->right; //出栈的时候就访问它的右子树
            stk.pop();
        }
    }
}

void inorder(TreeNode *root){
    stack<TreeNode*> stk;
    TreeNode *p=root;
    while(p!=NULL || !stk.empty()){
        while(p!=NULL){
            stk.push(p);
            p=p->left;
        }
        if(!stk.empty()){
            p=stk.top();            
            do_something(p);
            stk.pop();
            p=p->right;
        }
    }
}

void postorder(TreeNode *root){
    TreeNode *cur,*pre;
    pre=NULL;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        cur=stk.top();
        if((cur->left==NULL && cur->right==NULL)||
        (pre!=NULL && (pre==cur->left||pre==cur->right) ))
        {
            //如果当前栈顶节点不存在左右子树，或者左右子树已经被访问过了，则直接访问自己
            do_something(cur);
            stk.pop();
            pre=cur;
        }else{
            //否则需要将当前节点的左右子树压入栈中
            //注意压栈顺序，要先压右子树！！
            if(cur->right!=NULL)
                stk.push(cur->right);
            if(cur->left!=NULL)
                stk.push(cur->left);
        }
    }
}

void bfs(TreeNode *root){
    if(root==NULL)
        return;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *cur;
    while(!q.empty()){
        cur=q.front();
        do_something(cur);
        q.pop();
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}

int main(){
    int n=10;
    TreeNode* heap[10];
    for(int i=n-1;i>=0;i--){
        heap[i]=new TreeNode(i);
        if(i*2+1<n) heap[i]->left=heap[i*2+1];
        if(i*2+2<n) heap[i]->right=heap[i*2+2];
    }

    cout<<"bfs:";bfs(heap[0]);cout<<endl;
    
    cout<<"递归:"<<endl;
    cout<<"先序:";recursive_preorder(heap[0]);cout<<endl;
    cout<<"中序:";recursive_inorder(heap[0]);cout<<endl;
    cout<<"后序:";recursive_postorder(heap[0]);cout<<endl;

    cout<<"非递归:"<<endl;
    cout<<"先序:";preorder(heap[0]);cout<<endl;
    cout<<"中序:";inorder(heap[0]);cout<<endl;
    cout<<"后序:";postorder(heap[0]);cout<<endl;
    
    return 0;
}