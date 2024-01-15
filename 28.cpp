//
// Created by fyz on 2023/12/2.
//chatgpt改的同学的，改成vector数组了
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> zhishu;
vector<vector<int>> Tree;
int maxzhishu = 0;

// 递归计算最大值
int jisuan(int root) {
    // 如果节点没有子节点
    if (Tree[root].empty()) {
        // 如果节点的zhishu值为负数，则返回0；否则返回节点的zhishu值
        if (zhishu[root] < 0) {
            return 0;
        } else {
            return zhishu[root];
        }
    } else {
        int sum = 0;
        vector<int> child;
        // 计算每个子节点的值并求和
        for (int i = 0; i < Tree[root].size(); i++) {
            child.push_back(jisuan(Tree[root][i]));
            sum += child[i];
        }
        // 如果节点的zhishu值为负数，则更新maxzhishu为子节点中的最大值
        if (zhishu[root] < 0) {
            for (int i = 0; i < child.size(); i++) {
                if (maxzhishu < child[i]) {
                    maxzhishu = child[i];
                }
            }
        }
        // 如果节点的zhishu值加上子节点的和为负数，则返回0；否则返回节点的zhishu值加上子节点的和
        if (zhishu[root] + sum < 0) {
            return 0;
        } else {
            return zhishu[root] + sum;
        }
    }
}

int main() {
    int root, n;
    cin >> n;

    zhishu.resize(n + 1);
    Tree.resize(n + 1);

    // 读取每个节点的zhishu值并初始化Tree数组
    for (int i = 1; i <= n; i++) {
        cin >> zhishu[i];
    }

    // 构建树结构并确定根节点
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (i == 1) {
            root = x;
        }
        Tree[x].push_back(y);
    }

    // 计算最大值并输出
    int sum = jisuan(root);
    cout << max(sum, maxzhishu);
}
