//
// Created by fyz on 2023/11/27.
//
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    string TreeNode[102], s;
    int l = 0;
    while (cin >> s)
    {
        l++;
        TreeNode[l] = s;
    }
    string x = TreeNode[l - 1];
    string y = TreeNode[l];
    l -= 2;
    int locationx, locationy;
    for (int i = 1; i <= l; i++)
    {
        if (TreeNode[i] == x)
        {
            locationx = i;
        }
        if (TreeNode[i] == y)
        {
            locationy = i;
        }
    }
    int hx = floor(log2(locationx)), hy = floor(log2(locationy));
    int px = locationx / 2, py = locationy / 2;
    if (hx == hy && px != py)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}