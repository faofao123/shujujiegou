//
// Created by fyz on 2023/11/27.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool judge(const string s) {//判断是不是回文数
    string res = s;
    reverse(res.begin(), res.end());
    return res == s;
}

bool isAllNine(const string s) {//判断是不是全是9
    for (char ch: s) {
        if (ch != '9') {
            return false; // 只要有一个字符不是 '9'，就返回 false
        }
    }
    return true; // 如果整个字符串都是 '9'，返回 true
}

string symmetry(const string s, int len, int mid) {//轴对称得到回文数
    if (len % 2 == 0) {
        string right = s.substr(0, mid + 1);
        string left = s.substr(0, mid + 1);
        reverse(right.begin(), right.end());
        return left + right;
    } else {
        string right = s.substr(0, mid);
        string left = s.substr(0, mid);
        reverse(right.begin(), right.end());
        return left + s[mid] + right;
    }
}

int minpalindrome(const string s, int len, int mid) {//不小于给定数的最小回文数
    string next = s;
    if (judge(s)) {//本身是回文数
        if (isAllNine(s)) {//全是9的情况
            next[0] = next[len] = '1';
            for (int i = 1; i < len; i++)next[i] = '0';
            return stoi(next);
        } else if(s[mid]!='9'){//中间不为9
            next[mid]=next[len-1-mid]=next[mid]+1;
            return stoi(next);
        }else{//中间为9
            for(int i=mid;i>=0;i--){
                if(s[i]!='9'){//从中间往两边找到第一对不为9的数
                    next[i]=next[len-1-i]=next[i]+1;
                    break;
                }
                else next[i]=next[len-1-i]='0';
            }
            return stoi(next);
        }
    } else {//本身不是回文数
        next = symmetry(s, len, mid);//轴对称
        int x = stoi(s);
        int y = stoi(next);
        if (y > x)return y;//反转后的数比原来大
        else return minpalindrome(next, len, mid);//反转后的数比原来小，此时将反转后的数按本身是回文数的第一种情况处理
    }
}

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int mid = len & 1 ? len / 2 : len / 2 - 1;/*
 * 如果len是奇数，表达式len&1将返回true，否则返回false。
 * 如果字符串的长度是奇数，len/2 将是中间元素的索引；如果长度是偶数，len/2-1 将是左边靠近中心的元素索引。*/
    cout << minpalindrome(s, len, mid) << endl;
    return 0;
}