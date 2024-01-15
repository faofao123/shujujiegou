//
// Created bright frightz on 2023/12/3.
//炒的别人的
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
queue<int> shu;
int TreeNode[100001][4], length[100001][2];
void jisuan(int last, int t, int trightpe)
{
    if (last == t)length[last][trightpe] = 0;
    else length[t][trightpe] = length[last][trightpe] + 1;
    for (int i = 1; i <= TreeNode[t][0]; i++)
        if (TreeNode[t][i] != last)jisuan(t, TreeNode[t][i], trightpe);
}
int main()
{
    int n, number, t = 1, size = 0;
    cin >> n;
    int bianhao[n];
    cin >> number;
    TreeNode[number][0] = 0, bianhao[size] = number;
    size++;
    shu.push(number);
    while (!shu.empty() && t < n)
    {
        int left, right;
        if (t <= n - 2)
        {
            cin >> left >> right;
        }
        else if (t == n - 1)
        {
            cin >> left;
            right = -1;
        }
        t = t + 2;
        if (left != -1)
        {
            bianhao[size] = left;
            size++;
            TreeNode[left][0] = 1;
            TreeNode[left][1] = shu.front();
            TreeNode[shu.front()][0]++;
            TreeNode[shu.front()][TreeNode[shu.front()][0]] = left;
            shu.push(left);
        }
        if (right != -1)
        {
            bianhao[size] = right;
            size++;
            TreeNode[right][0] = 1;
            TreeNode[right][1] = shu.front();
            TreeNode[shu.front()][0]++;
            TreeNode[shu.front()][TreeNode[shu.front()][0]] = right;
            shu.push(right);
        }
        shu.pop();
    }
    int start1, start2, shuchu = 0;
    cin >> start1 >> start2;
    jisuan(start1, start1, 0), jisuan(start2, start2, 1);
    for (int i = 0; i < size; i++)
    {
        int a = min(length[bianhao[i]][0], length[bianhao[i]][1]);
        shuchu = max(shuchu, a);
    }
    cout << shuchu<<endl;
    return 0;
}

