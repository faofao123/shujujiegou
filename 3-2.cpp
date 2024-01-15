//
// Created by fyz on 2023/11/28.
//
#include <iostream>
#include <vector>
using namespace std;
bool isALlzero(vector<int>&a){
    for(int x:a){
        if(x!=0)return false;
    }
    return true;
}
void calculateProduct(string & l, string & r) {
    int m=l.length(),n=r.length();
    if(m==0||n==0)cout<<0;
    else {
        vector<int> shuchu(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            int x = l.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = r.at(j) - '0';
                shuchu[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            shuchu[i - 1] += shuchu[i] / 10;
            shuchu[i] %= 10;
        }
        if(isALlzero(shuchu))cout<<0;
        else {
            int a;
            if (shuchu[0] == 0) {
                a = 1;
            } else a = 0;
            for (int i = a; i < m + n; i++) {
                cout << shuchu[i];
            }
        }
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    string l,r;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int num=c-'0';
        if (num < x) {
            l.push_back(c);
        } else {
            r.push_back(c);
        }
    }

    calculateProduct(l, r);

    return 0;
}
