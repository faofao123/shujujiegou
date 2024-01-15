//
// Created by fyz on 2023/12/3.
//这题简单
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int shuchu = 0, chezhan = 0;
    int shangche[1000001] = {0};
    int xiache[1000001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        chezhan = max(chezhan, y);
        shangche[x]++;
        xiache[y]++;
    }
    int renshu = 0;
    for (int i = 0; i < chezhan; i++)
    {
        renshu = renshu + shangche[i+1] - xiache[i+1];
        shuchu = max(shuchu, renshu);
    }
    cout << shuchu<<endl;
}
