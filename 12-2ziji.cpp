//
// Created by fyz on 2023/12/5.
//
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
class Solution2 {
public:
    int max=0;
    int  dfs(TreeNode* root, int start,int sum){
        if(root==nullptr)return -1;
        if(sum==-1&&root->val==start){//本节点为感染节点
            sum=0;
        }
        if(sum!=-1){//本节点已感染，传递到子树中
            dfs(root->left,start,sum+1);
            dfs(root->right,start,sum+1);
            if(sum>max)max=sum;
            return sum+1;
        }else{
            int tem=dfs(root->left,start,sum);
            if(tem!=-1){//左子树被感染，传递到右子树
                sum=tem;
                dfs(root->right,start,sum+1);
            }else{//右子树被感染，传递到左子树
                sum=dfs(root->right,start,sum);
                dfs(root->left,start,sum+1);
            }
        }
        if(sum>max)max=sum;
        if(sum!=-1)return sum+1;
        return -1;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start,-1);
        return max;
    }
};
int distance(TreeNode*root,TreeNode*Node,int index){
    if(root->val==Node->val){
        return index;
    }
    if(root->left!= nullptr)distance(root->left,Node,index+1);
    if(root->right!= nullptr)distance(root->right,Node,index+1);
}
void Create_TreeNode(TreeNode*& t,int x) {
    t = (TreeNode*)malloc(sizeof(struct TreeNode));
    t->val = x;
    t->left = t->right = nullptr;
}
//层次遍历序列建树
void Create_Level(TreeNode*& t,int n) {
    queue<TreeNode *> q;//一个队列，元素类型是节点指针
    int x;
    cin >> x;
    if (x != -1) {
        Create_TreeNode(t, x);
        q.push(t);
    }
    for(int i=0;i<(n-1)/2;i++) {
        TreeNode *s = q.front();//取出队头
        //创建左右子节点，注意，如果是-1代表没有节点，不用管它
        cin >> x;
        if (x != -1) {
            Create_TreeNode(s->left, x);
            q.push(s->left);
        }
        cin >> x;
        if (x != -1) {
            Create_TreeNode(s->right, x);
            q.push(s->right);
        }
        q.pop();
    }
}
TreeNode*search(TreeNode*root,int x){
    if(root== nullptr)return nullptr;
    if(root->val==x)return root;
    TreeNode*fan1=search(root->left,x);
    TreeNode*fan2=search(root->right,x);
    if(fan1!= nullptr)return fan1;
    else return fan2;
}
int main(){
    int n;
    cin >> n;
    Solution1 A;
    Solution2 B;
    TreeNode*root=new TreeNode(0);
    Create_Level(root,n);
    int x,y;
    cin>>x>>y;
    TreeNode*Node1= search(root,x);
    TreeNode*Node2= search(root,y);
    TreeNode*Node=A.lowestCommonAncestor(root,Node1,Node2);
    int a= distance(Node,Node1,0);
    int b= distance(Node,Node2,0);
    int shuchu1=(a+b)/2;
    int shuchu2=B.amountOfTime(Node1,x);
    int shuchu3=B.amountOfTime(Node2,y);
    int shuchu;
    shuchu=max(shuchu1,shuchu2);
    shuchu=max(shuchu,shuchu3);
    cout<<shuchu;
    return 0;
}