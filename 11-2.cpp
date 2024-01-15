//
// Created by fyz on 2023/11/26.
//
#include <iostream>
#include <queue>
using namespace std;
typedef struct Tree
{
    int high;
} *TreeNode;
queue<TreeNode> list;

int main() {
    int n;
    cin >> n;
    TreeNode root = new Tree;
    int a[31]={0};
    root->high = 1;
    a[1]=1;
    list.push(root);
    while (!list.empty()) {
        int x, y;
        cin >> x >> y;
        if (x != -1) {
            TreeNode left = new Tree;
            left->high = list.front()->high + 1;
            a[x] = left->high;
            list.push(left);
        }
        if (y != -1) {
            TreeNode right = new Tree;
            right->high = list.front()->high + 1;
            a[y] = right->high;
            list.push(right);
        }
        list.pop();
    }
    cout<<'1'<<' ';
    for (int i = 2; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cout << i << ' ';
        }
        else if (a[i] < a[i + 1]) {
            cout << i << ' ';
        }
    }
    cout<<n<<endl;
    return 0;
}
