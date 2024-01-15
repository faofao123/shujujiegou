//
// Created by fyz on 2023/12/2.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 通过前序遍历序列构建二叉树
TreeNode* buildTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}
// 查找节点p和q的最近公共祖先节点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    }

    return (left != nullptr) ? left : right;
}
TreeNode* search(TreeNode* root, int target) {
    if (!root) {
        return nullptr;
    }

    if (root->val == target) {
        return root;
    }

    TreeNode* leftSearch = search(root->left, target);
    TreeNode* rightSearch = search(root->right, target);

    if (leftSearch) {
        return leftSearch;
    }


    if (rightSearch) {
        return rightSearch;
    }


    return nullptr;
}
int shuchu(TreeNode* root,int a,int b){
    TreeNode *p=search(root,a);
    TreeNode *q=search(root,b);
    TreeNode *zuxian= lowestCommonAncestor(root,p,q);
    int fan=zuxian->val;
    return fan;

}
int main() {
    vector<int> shuru;
    int pVal, qVal;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>s){
        int num= stoi(s);
        shuru.push_back(num);

    }
    cin>>pVal>>qVal;
    int index=0;
    TreeNode* root = buildTree(shuru,index);

    int result = shuchu(root, pVal, qVal);
    cout << result << endl;

    return 0;
}
