//
// Created by fyz on 2023/11/29.
//chatgpt直接过了……
#include <iostream>
#include <string>
#include <vector>

bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3, int i, int j, int k, std::vector<std::vector<int>>& memo) {
    // 若 s1 和 s2 已经全部匹配到 s3 中，则说明匹配成功
    if (i == s1.length() && j == s2.length() && k == s3.length()) {
        return true;
    }

    // 如果已经计算过当前状态，直接返回结果
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // 检查 s1 和 s3 是否匹配
    bool matchS1 = (i < s1.length() && s1[i] == s3[k]) && isInterleave(s1, s2, s3, i + 1, j, k + 1, memo);

    // 检查 s2 和 s3 是否匹配
    bool matchS2 = (j < s2.length() && s2[j] == s3[k]) && isInterleave(s1, s2, s3, i, j + 1, k + 1, memo);

    // 记录当前状态
    memo[i][j] = (matchS1 || matchS2) ? 1 : 0;

    return memo[i][j];
}

bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3) {
    if (s1.length() + s2.length() != s3.length()) {
        return false;
    }

    std::vector<std::vector<int>> memo(s1.length() + 1, std::vector<int>(s2.length() + 1, -1));
    return isInterleave(s1, s2, s3, 0, 0, 0, memo);
}

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    bool result = isInterleave(s1, s2, s3);
    std::cout << (result ? "True" : "False") << std::endl;

    return 0;
}
