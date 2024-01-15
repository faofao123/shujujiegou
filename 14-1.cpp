//
// Created by fyz on 2023/12/6.
//力扣上有答案过了，原理应该是中序遍历单增
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}; //通过结构体内的方法初始化树的节点
}T;
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    pair<int,int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int index1 = -1, index2 = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                index2 = i + 1;
                if (index1 == -1) {
                    index1 = i;
                } else {
                    break;
                }
            }
        }
        int x = nums[index1], y = nums[index2];
        return {x, y};
    }

    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int,int> swapped= findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }
};
void PreCreateBiTree(TreeNode *&t)
{
    int num;
    cin>>num;
    if(num == -1)
    {
        t = nullptr;
    }
    else
    {
        t=new T;
        t->val=num;
        PreCreateBiTree(t->left);
        PreCreateBiTree(t->right);
    }
}
int main(){
    int n;
    cin>>n;
    TreeNode*root=new T;
    PreCreateBiTree(root);
    Solution A;
    vector<int>nums;
    A.inorder(root,nums);
    pair<int,int>a=A.findTwoSwapped(nums);
    if(a.first<a.second)cout<<a.first<<' '<<a.second;
    else cout<<a.second<<' '<<a.first;
}