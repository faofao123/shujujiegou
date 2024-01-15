//
// Created by fyz on 2023/11/29.
//
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
int main(){
    Solution A;
    int n,l,r;
    cin>>n;
    vector<vector<int>>b;
    vector<vector<int>>c;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        vector<int>a;
        a.push_back(l);
        a.push_back(r);
        b.push_back(a);
    }
    c=A.merge(b);
    for(int i=0;i<c.size();i++){
        cout<<c[i][0]<<' '<<c[i][1]<<endl;
    }
    return 0;
}