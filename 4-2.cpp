//
// Created by fyz on 2023/11/29.
//
#include <iostream>
#include <stack>
using namespace std;
stack<int>shuru;
int shuchu[1001]={0};
int main()
{
    int n;
    int top=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>shuchu[i];
    }
    for(int i=1;i<=n;i++){
        shuru.push(i);
        while(!shuru.empty()&&shuru.top()==shuchu[top]){
            shuru.pop();
            top++;
        }
    }
    if(shuru.empty())cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}