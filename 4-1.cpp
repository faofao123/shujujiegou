//
// Created by fyz on 2023/11/28.
//双循环环链还是不会捏
#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int num;
    struct Node *next;
};
struct Node * builtLink1(int len,int k){
    struct Node* head = nullptr;
    struct Node* tail = nullptr;
    for(int i=1;i<=len;i++){
        struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
        newNode->num=i;
        newNode->next=nullptr;
        if(head==nullptr){
            head=tail=newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    tail->next=head;
    for(int i=1;i<k;i++){
        tail=tail->next;
    }
    return tail;
}
struct Node * search(struct Node *tail,int k){
    struct Node* pre=tail;
    struct Node* cur;
    while(1){
        cur=pre->next;
        if(cur->num==k){
            return pre;
        }
        pre=pre->next;
    }
}
struct Node * builtLink2(int len,int k){
    struct Node* head = nullptr;
    struct Node* tail = nullptr;
    for(int i=len;i>=1;i--){
        struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
        newNode->num=i;
        newNode->next=nullptr;
        if(head==nullptr){
            head=tail=newNode;
        }
        else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    tail->next=head;
    tail= search(tail,k);
    return tail;
}
void shan(struct Node**tail,int m){
    if((*tail)->next==*tail)cout<<(*tail)->num<<endl;
    else {
        struct Node *pre = *tail;
        struct Node *cur = (*tail)->next;
        for (int i = 1; i < m; i++) {
            pre=pre->next;
            cur=cur->next;
        }
        pre->next=cur->next;
        cout<<cur->num<<' ';
        free(cur);
        return shan(&pre,m);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    struct Node* tail1= builtLink1(n,k);
    struct Node* tail2= builtLink2(n,k);
    shan(&tail1,m);
    shan(&tail2,m);
}