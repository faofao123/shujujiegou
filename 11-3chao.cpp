//
// Created by fyz on 2023/11/27.
//
#include <iostream>
#include <queue>
using namespace std;
typedef struct Tree
{
    int number;
    Tree *left, *right;
} *TreeNode;
queue<TreeNode> list;

int maxDepth(TreeNode root,int&res)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = maxDepth(root->left,res);
        int rightDepth = maxDepth(root->right,res);
        res=max(res,leftDepth+rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }
}
int diameter(TreeNode root){
    if(root==NULL){
        return 0;
    }
    int res=0;
    maxDepth(root,res);
    return res;
}
int main()
{
    int n;
    cin >> n;
    TreeNode root = new Tree;
    root->number = 0;
    list.push(root);
    while (!list.empty())
    {
        int x, y;
        cin >> x >> y;
        if (x != -1)
        {
            TreeNode left_in = new Tree;
            left_in->number = x;
            list.front()->left = left_in;
            list.push(left_in);
        }
        else
        {
            list.front()->left = NULL;
        }
        if (y != -1)
        {
            TreeNode right_ch = new Tree;
            right_ch->number = y;
            list.front()->right = right_ch;
            list.push(right_ch);
        }
        else
        {
            list.front()->right = NULL;
        }
        list.pop();
    }
    cout << 2 * (n - 1) - diameter(root);
    return 0;
}