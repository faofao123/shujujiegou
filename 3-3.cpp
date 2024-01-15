//
// Created by fyz on 2023/11/28.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string findmin(string num, int k) {
    vector<char> a;
    for (char & c: num) {
        while (a.size() > 0 && a.back() > c && k) {
            a.pop_back();
            k -= 1;
        }
        a.push_back(c);
    }

    for (; k > 0; --k) {
        a.pop_back();
    }

    string s = "";
    bool isLeadingZero = true;
    for (char & c: a) {//找到第一个不为0的数，去除前导零,太绝了！！！！
        if (isLeadingZero && c == '0') {
            continue;
        }
        isLeadingZero = false;
        s += c;
    }
    return s == "" ? "0" : s;
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    string ss= findmin(s,k);
    cout<<ss;
}