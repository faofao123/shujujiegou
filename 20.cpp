//
// Created by fyz on 2023/11/29.
//chatgpt一遍过？我题干还没看呢（苦笑）；看完了，挺简单的，主要是0/1边界处理，以及出现频率很高的上下左右向量！！！！
#include <iostream>
#include <vector>

using namespace std;

// 定义方向数组，包括上、下、左、右四个方向
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// 检查指定坐标是否在地图范围内
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 计算岛屿的周长
int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    int perimeter = 0;

    // 遍历整个地图
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) { // 如果当前格子是岛屿
                // 检查当前岛屿格子的周围
                for (int k = 0; k < 4; ++k) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    // 如果周围是水域或者超出边界，则周长加1
                    if (!isValid(newX, newY, n, m) || grid[newX][newY] == 0) {
                        perimeter++;
                    }
                }
            }
        }
    }

    return perimeter;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << endl;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = islandPerimeter(grid);
    cout << result << endl;

    return 0;
}
