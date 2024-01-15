//
// Created by fyz on 2023/12/31.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct People
{
    string name = "";
    People* left;
    People* right;
    int strength;
    int id;
    int h;
    People(const int _id, const int _s, const string _n)
            :id(_id)
            , left(NULL)
            , right(NULL)
            , strength(_s)
            ,name(_n)
            ,h(1)
    {}

};


class BSTree {

public:
    People* root;
    int size;
    BSTree() {
        root = NULL;
        size = 0;
    }

    BSTree(const BSTree & t)
    {
        root = _Copy(t.root);
    }

    People* _Copy(People* root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        People* copyPeople = new People(root->id,root->strength,root->name);
        copyPeople->left = _Copy(root->left);
        copyPeople->right = _Copy(root->right);
        return copyPeople;
    }

    BSTree& operator=(BSTree t)
    {
        swap(root, t.root);
        return *this;
    }

    People* add(People* cur, const int& id, const int& str, const string& na) {
        if (cur == NULL) {//空树直接new出节点并返回
            return new People(id,str,na);
        }
        else {
            if (cur->id < id) {//比当前节点大
                cur->right = add(cur->right,  id, str, na);//去cur的右边插入并将新的头部返回
            }

            else {
                cur->left = add(cur->left,  id, str, na);//去cur的左边插入并将新的头部返回
            }
            cur->h = max(cur->left != NULL ? cur->left->h : 0, cur->right != NULL ? cur->right->h : 0) + 1;//重新计算高度
            return maintain(cur);//对cur这个树进行调整
        }

    }
    bool Insert(const int& id, const int& str, const string& na) {
        /*People* lastPeople = findLastIndex(id);
        if (lastPeople && lastPeople->id == id) {
            return false;
        }
        else {*/
        size++;
        root = add(root, id,str,na);
        return true;

    }
    //找到最离id最近的节点
    People* findLastIndex(const int id) {

        People* pre = root;//记录前一个节点
        People* cur = root;
        while (cur) {
            pre = cur;
            if (cur->id == id) {
                break;
            }
            else if (cur->id > id) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return pre;
    }
    People* rightRotate(People* cur) {
        People* left = cur->left;
        cur->left = left->right;
        left->right = cur;
        cur->h = max((cur->left != NULL ? cur->left->h : 0), (cur->right != NULL ? cur->right->h : 0)) + 1;//更新高度
        left->h = max((left->left != NULL ? left->left->h : 0), (left->right != NULL ? left->right->h : 0)) + 1;//更新高度
        return left;//返回新的头
    }
    People* leftRotate(People* cur) {
        People* rightPeople = cur->right;
        cur->right = rightPeople->left;
        rightPeople->left = cur;
        cur->h = max((cur->left != NULL ? cur->left->h : 0), (cur->right != NULL ? cur->right->h : 0)) + 1;//更新高度
        rightPeople->h = max((rightPeople->left != NULL ? rightPeople->left->h : 0), (rightPeople->right != NULL ? rightPeople->right->h : 0)) + 1;//更新高度
        return rightPeople;//
    }

    People* maintain(People* cur) {
        if (cur == NULL) {return NULL;}
        int leftHeight = cur->left != NULL ? cur->left->h : 0;//计算出cur左树的高度
        int rightHeight = cur->right != NULL ? cur->right->h : 0;//计算出cur右树的高度
        if (abs(leftHeight - rightHeight) > 1) {//出现不平衡
            if (leftHeight > rightHeight) {//如果是左树高
                //把左树的左右子树的高度来出来比较看到底是左边高还是右边高
                int leftLeftHeight = cur->left != NULL && cur->left->left != NULL ? cur->left->left->h : 0;
                int leftRightHeight = cur->left != NULL && cur->left->right != NULL ? cur->left->right->h : 0;
                if (leftLeftHeight >= leftRightHeight) {//注意想等时只能右旋
                    cur = rightRotate(cur);
                }
                else {//左右双旋
                    cur->left = leftRotate(cur->left);
                    cur = rightRotate(cur);
                }
            }else {
                int rightLeftHeight = cur->right != NULL && cur->right->left != NULL ? cur->right->left->h : 0;
                int rightRightHeight = cur->right != NULL && cur->right->right != NULL ? cur->right->right->h : 0;
                if (rightRightHeight >= rightLeftHeight) {
                    cur = leftRotate(cur);
                }
                else {//右左双旋
                    cur->right = rightRotate(cur->right);
                    cur = leftRotate(cur);
                }
            }
        }
        return cur;//返回调整好的新头
    }
    People* FindID(const int id)
    {
        People* cur = root;
        while (cur)
        {
            if (cur->id < id){cur = cur->right;}
            else if (cur->id > id){cur = cur->left;}
            else{
                printf("%d ", cur->id);
                cout <<cur->name;
                printf(" %d\n",cur->strength);
                return cur;//题目保证有解了
            }
        }
    }
    void FindName(People* r,const string& s)//T.findname(T.root)
    {
        People* root1 = r;
        if (root1)
        {FindName(root1->left,s);
            if (root1->name==s) {
                printf("%d ", root1->id);
                cout << root1->name;
                printf(" %d\n", root1->strength);
            }FindName(root1->right,s);
        }
    }
    void FindCompareTwo(People* p, const int& flag, const int& value,const int& id1, const int& id2) {
        if (flag == 0) {//>
            People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag,value,id1,id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength > value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
        else if (flag == 1) {//<
            People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag, value, id1, id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength < value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
        else if (flag == 2) {//>=
            People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag, value, id1, id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength >= value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
        else if (flag == 3) {//<=
            People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag, value, id1, id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength <= value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
        else if (flag == 4) {//!=
            People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag, value, id1, id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength != value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
        else if (flag == 5) {People* root1 = p;
            if (root1){
                FindCompareTwo(root1->left, flag, value, id1, id2);
                if (root1->id > id2) {return;}
                if (root1->id >= id1 && root1->strength == value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }FindCompareTwo(root1->right, flag, value, id1, id2);
            }
        }
    }
    void FindCompareOne(People* p, const int& flag, const int& value) {
        if (flag == 0) {
            //>
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength > value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }
        }
        else if (flag == 1) {
            //<
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength < value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }
        }
        else if (flag == 2) {
            //>=
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength >= value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }
        }
        else if (flag == 3) {
            //<=
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength <= value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }

        }
        else if (flag == 4) {
            //!=
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength != value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }

        }
        else if (flag == 5) {
            People* root1 = p;
            if (root1)
            {
                FindCompareOne(root1->left, flag, value);
                if (root1->strength == value) {
                    printf("%d ", root1->id);
                    cout << root1->name;
                    printf(" %d\n", root1->strength);
                }
                FindCompareOne(root1->right, flag, value);
            }
        }

    }



    void Erase(int id) {
        if (root == NULL) {
            return;
        }
        if (containsKey(id)) {

            --size;
            root = Delete(root, id);
        }

    }

    bool containsKey(int key) {
        if (root == NULL) {
            return false;
        }
        People* lastNode = findLastIndex(key);
        return lastNode && key == lastNode->id ? true : false;
    }


    People* Delete(People* cur, int id) {
        if (cur->id < id) {
            cur->right = Delete(cur->right, id);//去我的右边删除并且返回新的头部
        }
        else if (cur->id > id) {
            cur->left = Delete(cur->left, id);//去我的左边删除并返回新的头部
        }
        else {
            if (cur->left == nullptr && cur->right == nullptr) {//叶子节点左右都为空
                delete cur;
                return nullptr;

            }
            else if (!cur->left && cur->right) {//左为空但右不为空
                People* subR = cur->right;
                delete cur;
                cur = subR;
            }
            else if (cur->left && !cur->right) {//右为空但左不为空
                People* subL = cur->left;
                delete cur;
                cur = subL;
            }
            else {//左右都不为空采用替换法删除既采用值的方式替代
                People* des = cur->right;//找到右树最左节点或者找到左树的最右节点都可以
                while (des->left)
                {
                    des = des->left;
                }
                //记录对应的值
                int t_id = des->id;
                int t_s = des->strength;
                string t_n = des->name;
                cur->right = Delete(cur->right, des->id);//找到我先不删调用Delete 将des删掉并将树调整好
                cur->id = t_id;
                cur->strength = t_s;
                cur->name = t_n;

            }
        }
        if (cur) {//重新计算高度
            cur->h = max(cur->left ? cur->left->h : 0, cur->right ? cur->right->h : 0) + 1;
        }

        return maintain(cur);//调整cur这颗树
    }


};



//分为两块，第一块就是数组直接id查，第二块就是people[m-1]后边要跟链表了


void Query(BSTree& T, string instr) {//传进来的去掉了“QUERY ”
    if (instr.find("name =") != string::npos) {
        instr.erase(0, 7);
        T.FindName(T.root, instr);

    }
    else if (instr.find("strength") != string::npos) {
        if (instr[0] == 's' && instr[1] == 't') {
            instr.erase(0, 9);
            int f;
            string temp = instr.substr(0, 2);
            if (temp == "> ") {
                f = 0;
                instr.erase(0, 2);
            }
            else if (temp == "< ") {
                f = 1;
                instr.erase(0, 2);
            }
            else if (temp == ">=") {
                f = 2;
                instr.erase(0, 3);
            }
            else if (temp == "<=") {
                f = 3;
                instr.erase(0, 3);
            }
            else if (temp == "!=") {
                f = 4;
                instr.erase(0, 3);
            }
            else if (temp == "= ") {
                f = 5;
                instr.erase(0, 2);
            }

            T.FindCompareOne(T.root, f, stoi(instr));
        }
        else {
            string temp_id1 = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            string temp_id2 = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            instr.erase(0, 9);
            int f;
            string temp = instr.substr(0, 2);
            if (temp == "> ") {
                f = 0;
                instr.erase(0, 2);
            }
            else if (temp == "< ") {
                f = 1;
                instr.erase(0, 2);
            }
            else if (temp == ">=") {
                f = 2;
                instr.erase(0, 3);
            }
            else if (temp == "<=") {
                f = 3;
                instr.erase(0, 3);
            }
            else if (temp == "!=") {
                f = 4;
                instr.erase(0, 3);
            }
            else if (temp == "= ") {
                f = 5;
                instr.erase(0, 2);
            }


            T.FindCompareTwo(T.root, f, stoi(instr), stoi(temp_id1), stoi(temp_id2));
        }

    }
    else {
        T.FindID(stoi(instr));
    }

}

int main() {
    int n, m;
    cin >> m >> n;
    BSTree T;
    string na = "";
    int s;
    int id;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &id);
        cin >> na;
        scanf("%d", &s);
        T.Insert(id, s, na);
    }
    getline(cin, na);
    for (int i = 0; i < n; ++i) {
        string instr;
        getline(cin, instr);

        if (instr.find("QUERY") != string::npos) {
            instr.erase(0, 6);
            Query(T, instr);
        }
        else if (instr.find("DELETE") != string::npos) {
            instr.erase(0, 7);
            if (instr.find(" ") == string::npos) {
                T.Erase(stoi(instr));
            }
            else {
                string temp = instr.substr(0, instr.find_first_of(" "));
                instr.erase(0, instr.find_first_of(" ") + 1);
                for (int i = stoi(temp); i <= stoi(instr); ++i) {
                    T.Erase(i);
                }
            }
        }
        else {
            instr.erase(0, 7);
            string temp_id = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            string temp_name = instr.substr(0, instr.find_first_of(" "));
            instr.erase(0, instr.find_first_of(" ") + 1);
            string temp_strength = instr.substr(0, instr.find_first_of(" "));
            T.Insert(stoi(temp_id),stoi(temp_strength),temp_name);
        }

    }


    return 0;
}
