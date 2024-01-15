//
// Created by fyz on 2023/12/6.
//chatgpt一遍过，题还没看
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // 初始化结果为 -1
    stack<int> st; // 创建栈存放数组索引

    for (int i = 0; i < n * 2; ++i) {
        int num = nums[i % n];

        while (!st.empty() && nums[st.top()] < num) {
            result[st.top()] = num;
            st.pop();
        }

        if (i < n) {
            st.push(i);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElements(nums);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

