//
// Created by fyz on 2023/11/26.
//
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int main()
{
    string TreeNode[102], s,input,x,y;
    getline(cin,input);
    stringstream ss(input);
    int l = 0;
    while (ss>>s)
    {
        l++;
        TreeNode[l] = s;
    }
    cin>>x>>y;
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

