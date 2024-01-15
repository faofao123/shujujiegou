//
// Created by fyz on 2023/12/2.
//这个太长了，chatgpt也改不了同学的，估计有可能被查
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
typedef struct TreeNode
{
    int CHeck;
    int NUM;
    TreeNode *leftchild, *rightchild, *father;
};
queue<TreeNode *> List;

typedef struct TEAM
{
    int sumary, length;
    TreeNode *h, *highest, *t;
} *team;
team ac, ver;

team jisuan(TreeNode *root)
{
    if (root == nullptr)
    {
        team tip = new TEAM;
        tip->sumary = 0, tip->length = 0;
        return tip;
    }
    team left = jisuan(root->leftchild);
    team right = jisuan(root->rightchild);
    team tip = new TEAM;
    if (left->sumary == 0 && right->sumary == 0)
    {
        if (root->NUM <= 0)
        {
            tip->sumary = 0;
            tip->length = 0;
        }
        else
        {
            tip->sumary = root->NUM;
            tip->length = 1;
            tip->h = root;
            tip->t = root;
            tip->highest = nullptr;
        }
    }
    else
    {
        int blance = 0;
        if (left->sumary > right->sumary)blance = 1;
        else if (left->sumary < right->sumary)blance = 2;
        else
        {
            if (left->length < right->length)blance = 1;
            else if (left->length > right->length)blance = 2;
        }

        if (blance == 1)
        {
            if (root->NUM + left->sumary <= 0)
            {
                tip->sumary = 0;
                tip->length = 0;
            }
            else
            {
                tip->sumary = left->sumary + root->NUM;
                tip->length = left->length + 1;
                tip->h = left->h;
                tip->t = root;
                tip->highest = nullptr;
            }
        }
        else if (blance == 2)
        {
            if (root->NUM + right->sumary <= 0)
            {
                tip->sumary = 0;
                tip->length = 0;
            }
            else
            {
                tip->sumary = right->sumary + root->NUM;
                tip->length = right->length + 1;
                tip->h = right->h;
                tip->t = root;
                tip->highest = nullptr;
            }
        }
    }

    if (left->sumary > 0 && right->sumary > 0)
    {
        if (ac->sumary < root->NUM + left->sumary + right->sumary)
        {
            ac->sumary = root->NUM + left->sumary + right->sumary;
            ac->length = 1 + left->length + right->length;
            ac->h = left->h;
            ac->t = right->h;
            ac->highest = root;
        }
        else if (ac->sumary == root->NUM + left->sumary + right->sumary)
        {
            if (ac->length > 1 + left->length + right->length)
            {
                ac->sumary = root->NUM + left->sumary + right->sumary;
                ac->length = 1 + left->length + right->length;
                ac->h = left->h;
                ac->t = right->h;
                ac->highest = root;
            }
        }
    }
    if (ver->sumary < tip->sumary)ver = tip;
    else if (ver->sumary == tip->sumary)
    {
        if (ver->length > tip->length)ver = tip;
    }
    return tip;
}
int main()
{
    TreeNode *root = nullptr;
    int n, x;
    cin >> n >> x;
    int sumary = 0, NUM = 0;
    if (x == 0)
    {
        cout << 0;
        exit(0);
    }
    else
    {
        root = new TreeNode;
        root->CHeck = NUM;
        NUM++, sumary++;
        root->NUM = x;
        root->father = nullptr;
        root->leftchild = nullptr;
        root->rightchild = nullptr;
        List.push(root);
    }
    while (!(List.empty()) && sumary < n)
    {
        int a, b;
        cin >> a >> b;
        sumary += 2;
        if (a != 0)
        {
            TreeNode *left = new TreeNode;
            left->CHeck = NUM;
            NUM++;
            left->NUM = a;
            left->leftchild = nullptr;
            left->rightchild = nullptr;
            List.front()->leftchild = left;
            left->father = List.front();
            List.push(left);
        }
        if (b != 0)
        {

            TreeNode *right = new TreeNode;
            right->CHeck = NUM;
            NUM++;
            right->NUM = b;
            right->leftchild = nullptr;
            right->rightchild = nullptr;
            List.front()->rightchild = right;
            right->father = List.front();
            List.push(right);
        }
        List.pop();
    }
    ac = new TEAM, ver = new TEAM;
    ac->sumary = 0, ver->sumary = 0;
    ac->length = 0, ver->length = 0;
    team the = jisuan(root);
    int cho;
    if (ver->sumary > ac->sumary)cho = 1;
    else if (ver->sumary < ac->sumary)cho = 2;
    else
    {
        if (ver->length < ac->length)cho = 1;
        else if (ver->length > ac->length)cho = 2;
    }
    if (cho == 1)
    {
        int ans[n], Num = 0;
        TreeNode *tip = ver->h;
        while (tip != ver->t->father)
        {
            ans[Num] = tip->CHeck;
            tip = tip->father;
            Num++;
        }
        if (ver->h->CHeck < ver->t->CHeck)
        {
            for (int i = 0; i < Num; i++)cout << ans[i] << " ";
        }
        else
        {
            for (int i = Num - 1; i >= 0; i--)cout << ans[i] << " ";
        }
    }
    else
    {
        int ans1[n], ans2[n], Num1 = 0, Num2 = 0;
        TreeNode *tip1 = ac->h;
        TreeNode *tip2 = ac->t;
        while (tip1 != ac->highest->father)
        {
            ans1[Num1] = tip1->CHeck;
            tip1 = tip1->father;
            Num1++;
        }
        while (tip2 != ac->highest->father)
        {
            ans2[Num2] = tip2->CHeck;
            tip2 = tip2->father;
            Num2++;
        }
        if (ac->h->CHeck < ac->t->CHeck)
        {
            for (int i = 0; i < Num1; i++)cout << ans1[i] << " ";
            for (int i = Num2 - 2; i >= 0; i--)cout << ans2[i] << " ";
        }
        else
        {
            for (int i = 0; i < Num2; i++)cout << ans2[i] << " ";
            for (int i = Num1 - 2; i >= 0; i--)cout << ans1[i] << " ";
        }
    }
    return  0;
}