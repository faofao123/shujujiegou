//
// Created by fyz on 2023/11/30.
//又是你哈希表，学习了一下前缀和，这题思路简直太神了
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int cishu(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto &x: nums) {
        pre += x;
        if (mp.count(pre-x)) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}

int main(){
    int n,k;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    cin>>k;
    int shuchu=cishu(a,k);
    cout<<shuchu;
    return 0;
}

