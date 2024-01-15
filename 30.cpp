//
// Created by fyz on 2023/12/2.
//网上抄的
#include<vector>
#include<iostream>
using namespace std;

void dfs(vector<vector<int>>& tree, vector<int>& dis, int u, int fa, int step)
{
    for(int v :tree[u])
    {
        if(v==fa) continue;
        dis[v]=step+1;
        dfs(tree,dis,v,u,step+1);
    }
}

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<int>> tree(n+1);
    int out = 0;
    for(int i = 1; i <= n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> disx(n+1, 0);
    vector<int> disy(n+1, 0);
    dfs(tree, disx, x, -1, 0);
    dfs(tree, disy, y, -1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(disx[i]>disy[i])
            out = max(out, disx[i]);
    }
    cout<<out;
    return 0;
}
