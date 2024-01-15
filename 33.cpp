//
// Created by fyz on 2023/12/2.
//chatgpt一遍过还没看题
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

int ind = 0; // 全局变量，用于遍历输入字符串

TreeNode* buildTree(string preorder) {
    if (ind >= preorder.length() || preorder[ind] == '@') {
        ind++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[ind++]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data;
}

int main() {
    string input ;
    cin>>input;
    TreeNode* root = buildTree(input);

    postorderTraversal(root);
    cout << endl;

    return 0;
}
