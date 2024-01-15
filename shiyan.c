//
// Created by fyz on 2023/11/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent; // 添加指向父节点的指针
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

struct TreeNode* buildTree(char* nodes[], int size) {
    if (size <= 0) {
        return NULL;
    }

    struct TreeNode* treeNode[size];

    for (int i = 0; i < size; i++) {
        if (strcmp(nodes[i], "#") == 0) {
            treeNode[i] = NULL;
        } else {
            treeNode[i] = createNode(atoi(nodes[i]));
        }
    }

    for (int i = 0; i < size; i++) {
        if (treeNode[i]) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < size) {
                treeNode[i]->left = treeNode[leftIndex];
                if (treeNode[leftIndex])
                    treeNode[leftIndex]->parent = treeNode[i]; // 设置左子节点的父节点
            }
            if (rightIndex < size) {
                treeNode[i]->right = treeNode[rightIndex];
                if (treeNode[rightIndex])
                    treeNode[rightIndex]->parent = treeNode[i]; // 设置右子节点的父节点
            }
        }
    }

    return treeNode[0];
}
// ...（前面的代码和结构体定义，包括构建树的函数等）

void findDepthAndParent(struct TreeNode* root, int val, int* depth, struct TreeNode** parent) {
    if (root == NULL) {
        return;
    }

    if (root->val == val) {
        return;
    }

    if (root->left) {
        if (root->left->val == val) {
            *depth += 1;
            *parent = root;
            return;
        } else {
            findDepthAndParent(root->left, val, depth, parent);
        }
    }

    if (root->right) {
        if (root->right->val == val) {
            *depth += 1;
            *parent = root;
            return;
        } else {
            findDepthAndParent(root->right, val, depth, parent);
        }
    }
}

bool isCousin(struct TreeNode* root, int x, int y) {
    int x_depth = 0, y_depth = 0;
    struct TreeNode* x_parent = NULL;
    struct TreeNode* y_parent = NULL;

    findDepthAndParent(root, x, &x_depth, &x_parent);
    findDepthAndParent(root, y, &y_depth, &y_parent);

    return (x_depth == y_depth) && (x_parent != y_parent);
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string by space
    char *nodes_input[100];
    char *token = strtok(input, " \n");
    int size = 0;

    while (token != NULL) {
        nodes_input[size++] = token;
        token = strtok(NULL, " \n");
    }

    struct TreeNode* root = buildTree(nodes_input, size);

    int x_value ; // 你要判断的第一个节点的值
    int y_value ; // 你要判断的第二个节点的值
    scanf("%d%d",&x_value,&y_value);
    bool result = isCousin(root, x_value, y_value);

    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
