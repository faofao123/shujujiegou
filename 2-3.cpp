//
// Created by fyz on 2023/11/27.
//从chatgpt上复制的，没想到一下子就成功了，主要考察栈啊！！！！！
#include <iostream>
#include <stack>
#include <string>

int scoreOfParentheses(int length, std::string& S) {
    std::stack<int> st;
    int score = 0;

    for (int i = 0; i < length; ++i) {
        if (S[i] == '(') {
            st.push(0);
        } else {
            if (st.top() == 0) {
                st.pop();
                st.push(1);
            } else {
                int inner = 0;
                while (st.top() != 0) {
                    inner += st.top();
                    st.pop();
                }
                st.pop();
                st.push(inner * 2);
            }
        }
    }

    while (!st.empty()) {
        score += st.top();
        st.pop();
    }

    return score;
}

int main() {
    int length;
    std::string S;

    std::cin >> length >> S;

    int result = scoreOfParentheses(length, S);
    std::cout << result << std::endl;

    return 0;
}
