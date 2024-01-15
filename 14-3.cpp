//
// Created by fyz on 2023/12/6.
//chatgpt一遍过，没看题
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int maxBalanceFactor(TreeNode* root, int& maxDiff) {
    if (root == nullptr) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int balanceFactor = abs(leftHeight - rightHeight);
    maxDiff = max(maxDiff, balanceFactor);

    maxBalanceFactor(root->left, maxDiff);
    maxBalanceFactor(root->right, maxDiff);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> preorder(N);
    for (int i = 0; i < N; ++i) {
        cin >> preorder[i];
    }

    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    int maxDiff = 0;
    maxBalanceFactor(root, maxDiff);

    cout << maxDiff << endl;

    return 0;
}
