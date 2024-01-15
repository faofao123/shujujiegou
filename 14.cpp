//
// Created by fyz on 2023/11/29.
//
#include <iostream>
#include <vector>
using namespace std;
int maxqian(vector<vector<int>>&piles,int k){
    vector<int> f(k + 1);
    int sumN = 0;
    for (auto &pile: piles) {
        int n = pile.size();
        for (int i = 1; i < n; ++i)
            pile[i] += pile[i - 1]; // pile 前缀和
        sumN = min(sumN + n, k); // 优化：j 从前 i 个栈的大小之和开始枚举（不超过 k）
        for (int j = sumN; j; --j)
            for (int w = 0; w < min(n, j); ++w)
                f[j] = max(f[j], f[j - w - 1] + pile[w]); // w 从 0 开始，物品体积为 w+1
    }
    return f[k];
}
int main() {
    int n, k,num,len;
    cin>>n>>k;
    vector<vector<int>>piles;
    for(int i=0;i<n;i++){
        cin>>len;
        vector<int>a;
        for(int j=0;j<len;j++){
            cin>>num;
            a.push_back(num);
        }
        piles.push_back(a);
    }
    cout<<maxqian(piles,k);
    return 0;
}