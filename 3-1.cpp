//
// Created by fyz on 2023/11/28.
//从chatgpt上复制的，没想到一下子就成功了……
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> below_20 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
};

std::vector<std::string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

std::vector<std::string> thousands = {"", "Thousand", "Million", "Billion"};

std::string helper(int num) {
    if (num == 0) {
        return "";
    } else if (num < 20) {
        return below_20[num] + " ";
    } else if (num < 100) {
        return tens[num / 10] + " " + helper(num % 10);
    } else {
        return below_20[num / 100] + " Hundred " + helper(num % 100);
    }
}
std::string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    std::string result;
    int i = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            result = helper(num % 1000) + thousands[i] + " " + result;
        }
        num /= 1000;
        i++;
    }

    while (result.back() == ' ') {
        result.pop_back();
    }

    return result;
}



int main() {
    int num;
    std::cin >> num;

    std::string result = numberToWords(num);
    std::cout << result << std::endl;

    return 0;
}
