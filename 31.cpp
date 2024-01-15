//
// Created by fyz on 2023/12/2.
//chatgpt直接过了，还没看题
#include <iostream>
#include <queue>

using namespace std;

string predictPartyVictory(string senate) {
    queue<int> radiant, dire;
    int n = senate.size();

    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') radiant.push(i);
        else dire.push(i);
    }

    while (!radiant.empty() && !dire.empty()) {
        int r_index = radiant.front();
        int d_index = dire.front();
        radiant.pop();
        dire.pop();

        if (r_index < d_index) radiant.push(r_index + n); // 重新进入队列
        else dire.push(d_index + n); // 重新进入队列
    }

    return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
}

int main() {
    string input;
    cin>>input;
    string result = predictPartyVictory(input);
    cout <<  result << endl;
    return 0;
}
