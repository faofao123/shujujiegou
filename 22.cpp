//
// Created by fyz on 2023/11/30.
//chatgpt一遍过？我题干还没看呢（苦笑）；
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int findLuckyNumber(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rowMin(m, INT_MAX); // 用于存储每行的最小值，初始化为最大整数
    vector<int> colMax(n, INT_MIN); // 用于存储每列的最大值，初始化为最小整数

    // 找出每行的最小值和每列的最大值
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rowMin[i] = min(rowMin[i], matrix[i][j]);
            colMax[j] = max(colMax[j], matrix[i][j]);
        }
    }

    // 在行的最小值和列的最大值中寻找幸运数
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                return matrix[i][j];
            }
        }
    }

    return -1;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int luckyNumber = findLuckyNumber(matrix);
    cout << luckyNumber << endl;

    return 0;
}
