//
// Created by fyz on 2023/12/6.
//chatgpt一遍过，没看题
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (nums[i] != -1) {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && nums[i] != -1) {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

bool isAVL(TreeNode* root) {
    if (root == nullptr) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right)) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    if (isAVL(root)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
