//
// Created by fyz on 2023/12/20.
//力扣上有，还没看题……
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;

public:
    int find(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t) {
            for (auto&& flight: flights) {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};


int main() {
    int src, dst, k;
    cin >> src >> dst >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    Solution A;
    int result = A.find(n,flights,src,dst,k);
    cout << result << endl;

    return 0;
}
