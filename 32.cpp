//
// Created by fyz on 2023/12/2.
//自己终于写过了，原来这题好简单
#include <iostream>
#include <stack>
using namespace std;
stack<char>s;
int main() {
    string input;
    cin>>input;
    for(int i=0;i<input.size();i++){
        if(input[i]=='(')s.push('(');
        if(input[i]==',')continue;
        if(input[i]==')'){
            if(s.top()=='('){
                s.pop();
                s.push('@');
            }
            else s.push(')');
        }
        else s.push(input[i]);
    }
    while(!s.empty()){
        if(s.top()=='('||s.top()==')')s.pop();
        else {
            cout<<s.top();
            s.pop();
        }
    }
    return 0;
}
