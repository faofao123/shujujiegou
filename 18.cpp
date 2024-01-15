//
// Created by fyz on 2023/11/29.
//
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void shuchu(vector<int>&shuru,int n){
    deque<int> dq;
    for(int i=n-1;i>0;i--){
        dq.push_front(shuru[i]);
        int tail=dq.back();
        dq.pop_back();
        dq.push_front(tail);
    }
    dq.push_front(shuru[0]);
    for(int i=0;i<dq.size();i++){
        if(i==0)cout<<dq[i];
        else cout<<' '<<dq[i];
    }
}


int main() {

    int num,n;
    vector<int>shuru;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        shuru.push_back(num);
    }
    shuchu(shuru,n);
    return 0;
}
