//
// Created by fyz on 2023/11/27.
//
#include <iostream>
#include <queue>
using namespace std;
typedef struct Tree
{
    int num;
    int high;
    Tree *lkid, *rkid;
} *treemem;
queue<treemem> list;

int main()
{
    int n, num, all[30][2], maxhigh = 1;
    cin >> n;
    treemem root = new Tree;
    all[0][0] = 1, all[0][1] = 1;
    root->num = 1;
    root->high = 1;
    list.push(root);
    while (!list.empty())
    {
        int x, y;
        cin >> x >> y;
        if (x != -1)
        {
            treemem left = new Tree;
            left->num = x;
            left->high = list.front()->high + 1;
            list.front()->lkid = left;
            list.push(left);
            if (left->high > maxhigh)
            {
                all[maxhigh][0] = left->num;
                all[maxhigh][1] = left->num;
                maxhigh++;
            }
            else
            {
                all[maxhigh - 1][1] = left->num;
            }
        }
        if (y != -1)
        {
            treemem right = new Tree;
            right->num = y;
            right->high = list.front()->high + 1;
            list.front()->rkid = right;
            list.push(right);
            if (right->high > maxhigh)
            {
                all[maxhigh][0] = right->num;
                all[maxhigh][1] = right->num;
                maxhigh++;
            }
            else
            {
                all[maxhigh - 1][1] = right->num;
            }
        }
        list.pop();
    }
    for (int i = 1; i <= maxhigh; i++)
    {
        if (all[i - 1][0] == all[i - 1][1])
        {
            cout << all[i - 1][0] << " ";
        }
        else
        {
            cout << all[i - 1][0] << " " << all[i - 1][1] << " ";
        }
    }
}