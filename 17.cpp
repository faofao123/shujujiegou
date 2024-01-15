//
// Created by fyz on 2023/11/29.
//这题简单，chatgpt直接过了，不用看了
#include <iostream>
#include <vector>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& city) {
    int n = city.size();
    if (n == 0) return 0;

    vector<int> maxRow(n, 0);
    vector<int> maxCol(n, 0);

    // 计算每行每列的最大值
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxRow[i] = max(maxRow[i], city[i][j]);
            maxCol[j] = max(maxCol[j], city[i][j]);
        }
    }

    int increase = 0;

    // 计算增高建筑物的最大总和
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            increase += min(maxRow[i], maxCol[j]) - city[i][j];
        }
    }

    return increase;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> city(n, vector<int>(n));

    // 读取城市大楼的高度
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> city[i][j];
        }
    }

    // 计算建筑物增高的最大总和
    int result = maxIncreaseKeepingSkyline(city);

    // 输出建筑物增高的最大总和
    cout << result << endl;

    return 0;
}
