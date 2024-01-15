//
// Created by fyz on 2023/12/2.
//chatgpt一遍过还没看题
#include <iostream>
#include <algorithm>
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

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int diameter(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(max(leftDiameter, rightDiameter), leftHeight + rightHeight);
}

int main() {
    int length;
    cin >> length;

    string input;
    cin >> input;

    TreeNode* root = buildTree(input);

    int longestDistance = diameter(root);
    cout << longestDistance << endl;

    return 0;
}
