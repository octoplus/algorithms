#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v;
    node *left;
    node *right;
    node(int v, node *left, node *right) : v(v), left(left), right(right){};
    node() : v(0), left(NULL), right(NULL){};
};

bool path_print(node *root, node *target)
{
    if (root == NULL)
        return false;
    if (root == target)
    {
        cout << root->v << " ";
        return true;
    }
    if (path_print(root->left, target) || path_print(root->right, target))
    {
        cout << root->v << " ";
        return true;
    }
    return false;
}

int main()
{
    int n = 10;
    node a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].v = i;
        if ((i + 1) * 2 - 1 < n)
        {
            a[i].left = &a[(i + 1) * 2 - 1];
        }
        if ((i + 1) * 2 < n)
            a[i].right = &a[(i + 1) * 2];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].v << "," << a[i].left << "," << a[i].right << endl;
    }
    path_print(&a[0], &a[9]);
    cout << endl;
    return 0;
}