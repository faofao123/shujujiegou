//
// Created by fyz on 2024/1/21.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> g(n), grev(n);
        for (const auto& edge: edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            g[x].emplace_back(y, z);
            grev[y].emplace_back(x, z);
        }

        auto dijkstra = [&n](const vector<vector<pair<int, int>>>& graph, int start) -> vector<long long> {
            vector<long long> dist(n, -1);
            dist[start] = 0;
            vector<int> used(n);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.emplace(0, start);

            while (!q.empty()) {
                int u = q.top().second;
                q.pop();
                if (used[u]) {
                    continue;
                }
                used[u] = true;

                for (const auto& [v, weight]: graph[u]) {
                    long long target = dist[u] + weight;
                    if (dist[v] == -1 || target < dist[v]) {
                        dist[v] = target;
                        q.emplace(dist[v], v);
                    }
                }
            }

            return dist;
        };

        vector<long long> dist1 = dijkstra(g, src1);
        vector<long long> dist2 = dijkstra(g, src2);
        vector<long long> dist3 = dijkstra(grev, dest);

        long long ans = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1 && dist3[i] != -1) {
                long long result = dist1[i] + dist2[i] + dist3[i];
                if (ans == -1 || result < ans) {
                    ans = result;
                }
            }
        }

        return ans;
    }
};

int main() {
    int m, n, src1, src2, dest;
    cin >> m >> n >> src1 >> src2 >> dest;
    vector<vector<int>>edges(n);
    for (int i = 0; i < n; ++i) {
        int start, end, time;
        cin >> start >> end >> time;
        edges[i].push_back(start);
        edges[i].push_back(end);
        edges[i].push_back(time);
    }
    Solution A;
    long long a=A.minimumWeight(m,edges,src1, src2, dest);
    cout<<a<<endl;
    return 0;
}