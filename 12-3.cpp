//
// Created by fyz on 2023/12/3.
//抄的别人的没想到最后问题出在long long上
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    long long num;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

long long totalWeight(TreeNode* root) {
    if (root == nullptr) return 0;
    long long leftWeight = totalWeight(root->left);
    long long rightWeight = totalWeight(root->right);
    return leftWeight + rightWeight + root->num;
}

void swapNodes(TreeNode* root) {
    long long leftWeight = totalWeight(root->left);
    long long rightWeight = totalWeight(root->right);
    if (leftWeight > rightWeight) {
        swap(root->left, root->right);
    }
    if (root->left != nullptr)swapNodes(root->left);
    if (root->right != nullptr)swapNodes(root->right);

}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->num << " ";
    inorderTraversal(root->right);
}

int main() {
    long long n, newnode = 1;
    long long num;
    cin >> n >> num;
    queue<TreeNode*> nodes;
    TreeNode* root = new TreeNode;
    root->num = num;
    nodes.push(root);
    while (!nodes.empty() && newnode < n) {
        long long x, y;
        if (newnode <= n - 2) {
            cin >> x >> y;
        } else if (newnode == n - 1) {
            cin >> x;
        }

        TreeNode* left = new TreeNode;
        left->num = x;
        nodes.front()->left = left;
        nodes.push(left);

        if (newnode != n - 1) {
            TreeNode* right = new TreeNode;
            right->num = y;
            nodes.front()->right = right;
            nodes.push(right);
        }
        newnode += 2;
        nodes.pop();
    }
    swapNodes(root);
    inorderTraversal(root);

    return 0;
}
