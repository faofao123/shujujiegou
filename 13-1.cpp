//
// Created by fyz on 2023/12/6.
//chatgpt一遍过，题还没看
#include <iostream>
#include <vector>

using namespace std;

void printSpiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
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
    printSpiralOrder(matrix);

    return 0;
}
