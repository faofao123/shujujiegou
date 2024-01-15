//
// Created by fyz on 2023/12/31.
//
#include <iostream>
#include <vector>
#include <cmath>
#include<climits>
#include <cstring>
using namespace std;
struct Path {
    int from;
    int to;
    int cost;
    bool operator > (Path const& W) const {
        return cost > W.cost;
    }
    bool operator < (Path const& W) const {
        return cost < W.cost;
    }
};



template<typename T>//小顶堆
class minHeap {
public:
    int g_size;
    T* arr;
    minHeap(int n) {
        g_size = 0;
        arr = (T*)malloc(sizeof(T) * n);
    }
    bool empty() {
        return g_size == 0;
    }
    bool cmp(T a, T b){return a > b; //最小堆
    }
    void exchange(T* a, T* b)
    {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int LeftChild(int id){return id * 2;
    }
    int RightChild(int id){
        return id * 2 + 1;
    }
    int Parent(int id){
        return id / 2;
    }
    void AdjustHeap(int rootId, int size){
        int largest = rootId, left = LeftChild(rootId), right = RightChild(rootId);
        if (left < size && cmp(arr[largest], arr[left]))largest = left;
        if (right < size && cmp(arr[largest], arr[right]))largest = right;
        if (largest == rootId)return;
        exchange(arr + rootId, arr + largest);
        AdjustHeap(largest, size);
    }
    void HeapIncrese(int size, int id, T newValue){
        arr[id] = newValue;
        while (id > 0 && cmp(arr[Parent(id)], arr[id])) {
            exchange(arr + id, arr + Parent(id));
            id = Parent(id);
        }
    }
    void HeapInsert(int& size, T value){
        HeapIncrese(size + 1, size, value);
        size++;
    }
    T Top(){
        return arr[0];
    }
    void Push(T value){
        HeapInsert(g_size, value);
    }
    void Pop(){
        g_size--;
        exchange(arr, arr + g_size);
        AdjustHeap(0, g_size);
    }
};

struct Node
{
    int index;
    int dis;
    bool operator > (Node const& W) const {
        return dis > W.dis;
    }
    bool operator < (Node const& W) const {
        return dis < W.dis;
    }
};

struct List
{
    List* next;
    int to;
    int cost;
};

void insert(List* L, int to, int cost) {
    while (L->next != NULL) {
        L = L->next;
    }
    L->to = to;
    L->cost = cost;
    L->next = (List*)malloc(sizeof(List));
    L->next->next = NULL;
    L->next->to = -1;
}

int main() {//城市编号0-m-1
    int m, n, src1, src2, dest;
    cin >> m >> n >> src1 >> src2 >> dest;
    int* nums1 = new int[m];//nums1[i]表示从src1到编号为i的城市所用最小路径，无法到达则填MAX；
    memset(nums1, 1000000, sizeof(int) * m);
    int* nums2 = new int[m];//nums2[i]表示从src2到编号为i的城市所用最小路径，无法到达则填-1；
    memset(nums2, 1000000, sizeof(int) * m);
    int* nums3 = new int[m];//nums3[i]表示从dest到编号为i的城市所用最小路径，无法到达则填-1；
    memset(nums3, 1000000, sizeof(int) * m);
    List* path1 = (List*)malloc(sizeof(List) * m);//出边的链表
    List* path2 = (List*)malloc(sizeof(List) * m);//入边的链表
    for (int i = 0; i < m; ++i) {
        path1[i].next = NULL;
        path1[i].to = -1;
        path2[i].next = NULL;
        path2[i].to = -1;
    }
    minHeap<Node> mh1(m);
    minHeap<Node> mh2(m);
    minHeap<Node> mh3(m);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        insert(&path1[a], b, c);
        insert(&path2[b], a, c);
    }
    mh1.Push({ src1,0 });
    nums1[src1] = 0;
    int* visited = new int[m];
    memset(visited, 0, sizeof(int) * m);
    while (!mh1.empty()) {
        Node temp = mh1.Top();
        mh1.Pop();
        if (visited[temp.index])continue;
        visited[temp.index] = true;
        List* p = &path1[temp.index];
        while (p->to != -1) {
            if (nums1[p->to] > p->cost + nums1[temp.index]){
                nums1[p->to] = p->cost + nums1[temp.index];
                mh1.Push({ p->to ,nums1[p->to] });
            }
            p = p->next;
        }
    }
    nums2[src2] = 0;
    memset(visited, 0, sizeof(int) * m);
    mh2.Push({ src2,0 });
    nums2[src2] = 0;
    while (!mh2.empty()) {
        Node temp = mh2.Top();
        mh2.Pop();
        if (visited[temp.index])continue;
        visited[temp.index] = true;
        List* p = &path1[temp.index];
        while (p->to != -1) {
            if (nums2[p->to] > p->cost + nums2[temp.index]) {
                nums2[p->to] = p->cost + nums2[temp.index];
                mh2.Push({ p->to ,nums2[p->to] });
            }
            p = p->next;
        }
    }
    nums3[dest] = 0;
    memset(visited, 0, sizeof(int) * m);
    mh3.Push({ dest,0 });
    nums3[dest] = 0;
    while (!mh3.empty()) {
        Node temp = mh3.Top();
        mh3.Pop();
        if (visited[temp.index])continue;
        visited[temp.index] = true;
        List* p = &path2[temp.index];
        while (p->to != -1) {
            if (nums3[p->to] > p->cost + nums3[temp.index]) {
                nums3[p->to] = p->cost + nums3[temp.index];
                mh3.Push({ p->to ,nums3[p->to] });
            }
            p = p->next;
        }
    }
    int res = INT_MAX - 1;
    for (int i = 0; i < m; ++i) {
        if (nums1[i] < 1000000 && nums2[i] < 1000000 && nums3[i] < 1000000) {
            int temp = nums1[i] + nums2[i] + nums3[i];
            if (temp < res) {
                res = temp;
            }
        }
    }
    res = res == INT_MAX - 1 ? -1 : res;
    cout << res;
    return 0;
}