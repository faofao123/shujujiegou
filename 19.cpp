//
// Created by fyz on 2023/11/29.
//完全没搞懂，不知道为什么一个点的横纵坐标会分开，抄的力扣
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class DisjointSetUnion {
private:
    unordered_map<int, int> f, rank;

public:
    int find(int x) {
        if (!f.count(x)) {
            f[x] = x;
            rank[x] = 1;
        }
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
    }

    int numberOfConnectedComponent() {
        int num = 0;
        for (auto &[x, fa] : f) {
            if (x == fa) {
                num++;
            }
        }
        return num;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        DisjointSetUnion dsu;
        for (int i = 0; i < n; i++) {
            dsu.unionSet(stones[i][0], stones[i][1] + 10001);
        }

        return n - dsu.numberOfConnectedComponent();
    }
};
int main(){
    int n,x,y;
    cin>>n;
    Solution A;
    vector<vector<int>> stones(n);
    for(int i=0;i<n;i++){
        cin>>x>>y;
        stones[i].push_back(x);
        stones[i].push_back(y);
    }
    int shuchu=A.removeStones(stones);
    cout<<shuchu;
    return 0;
}