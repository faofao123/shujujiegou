//
// Created by fyz on 2023/11/29.
//chatgpt直接过了……
#include <iostream>
#include <sstream>
#include <climits>

int myAtoi(const std::string& str) {
    std::istringstream iss(str);
    int result = 0;
    char sign = '+';

    iss >> std::ws; // 跳过前导空格

    // 处理正负号
    if (iss.peek() == '-' || iss.peek() == '+') {
        iss >> sign;
    }

    // 转换数字字符为整数值
    char digit;
    while (iss >> digit && isdigit(digit)) {
        int num = digit - '0';
        // 检查是否溢出
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && num > INT_MAX % 10)) {
            return (sign == '-') ? INT_MIN : INT_MAX;
        }
        result = result * 10 + num;
    }

    return (sign == '-') ? -result : result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    int result = myAtoi(input);
    std::cout << result << std::endl;

    return 0;
}
