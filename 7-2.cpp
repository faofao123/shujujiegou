//
// Created by fyz on 2023/11/30.
//怎么又是动态规划，栈的方法实在不会，基础方法比较好理解left+right
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longest(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == 'S') {
                if (s[i - 1] == 'M') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == 'M') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

int main(){
    string s;
    cin>>s;
    Solution A;
    int shuchu=A.longest(s);
    cout<<shuchu;
    return 0;
}