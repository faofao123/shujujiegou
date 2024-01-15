//
// Created by fyz on 2023/12/2.
//chatgpt一遍过还没看题
#include <iostream>
#include <string>
#include <vector>
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

void printPaths(TreeNode* root, vector<char>& path) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr) {
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i];
        }
        cout << endl;
    } else {
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    path.pop_back();
}

int main() {
    string input ;
    cin>>input;
    TreeNode* root = buildTree(input);

    vector<char> path;
    printPaths(root, path);

    return 0;
}
