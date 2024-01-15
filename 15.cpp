//
// Created by fyz on 2023/11/29.
//chatgpt直接过了，函数部分没看懂
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
vector<int> dailyTemperatures(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    stack<int> indexStack;

    for (int i = 0; i < nums.size(); ++i) {
        while (!indexStack.empty() && nums[i] > nums[indexStack.top()]) {
            int idx = indexStack.top();
            indexStack.pop();
            result[idx] = i - idx;
        }
        indexStack.push(i);
    }

    return result;
}

int main() {
    vector<int> nums;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss>>s){
        int a= stoi(s);
        nums.push_back(a);
    }
    vector<int> result = dailyTemperatures(nums);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
