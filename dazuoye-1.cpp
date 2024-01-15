//
// Created by fyz on 2023/12/31.
//CSDN上找的，没想到直接把大作业全找出来了
#include <iostream>
#include <vector>
#include <cmath>
#include<climits>
using namespace std;
template <class T>
class MaxHeap {
private:
    int capacity;
    int curSize;
    T* data;
public:
    MaxHeap(int eleNums) : capacity(eleNums), curSize(0) // 构造函数
    {
        data = new T[eleNums + 4];
        data[0] = INT_MAX;                              // 索引为0的空间不存放有效数据,只作为辅助用，这个很重要
    }
    T GetMax() {
        if (curSize == 0)return -1;
        return data[1];
    }

    // 插入，使用空穴上浮
    void Insert(int x)
    {

        int i = curSize + 1;                             // 空穴的初始位置
        while (data[i / 2] < x)                           // 只要空穴值大于空穴的父节点值，空穴就要上浮
        {                                              // 索引为 0 的数的作用在这体现，使循环条件更简单
            data[i] = data[i / 2];                       // 空穴的父节点下沉
            i /= 2;                                      // 空穴上浮
        }
        data[i] = x;                                   // 给空穴赋值
        curSize++;                                     // 堆中有效数据加一
    }

    //删除，使用空穴下沉
    void RemoveMax(int& curMax)
    {
        if (curSize != 0)                                          // 删除前先判断堆中是否还有有效数据
        {
            curMax = data[1];                                  // 获取堆中当前最大值
            int i = 1;                                          // 空穴的初始位置
            int x = data[curSize--];                            // 空穴值取最后一个元素的值
            int child;                                          // 表示空穴孩子的位置
            while (i * 2 <= curSize)                                 // 空穴最多下沉到叶子节点，注意，不是一定下沉到叶子节点
            {
                child = i * 2;                                    // 先取空穴的左孩子位置
                if (child != curSize && data[child] < data[child + 1]) // 找出空穴的较大的孩子
                    child++;                                    // 空穴存在右孩子，且右孩子比左孩子大
                if (x < data[child])                             // 空穴值小于空穴的孩子值，那么空穴需要下沉，否则跳出循环
                {
                    data[i] = data[child];                      // 空穴的较大的孩子上浮
                    i = child;                                  // 空穴下沉
                }
                else
                    break;

            }
            data[i] = x;                                        // 将空穴值放入空穴位置
        }
    }
};




template <class T>
class MinHeap
{
public:
    MinHeap(int sz);		//构造函数，建立空堆
    MinHeap(T arr[], int n);			//构造函数，通过一个数组建立堆,这个数组有n个元素
    ~MinHeap() { delete[] heap; }		//析构函数

    bool Insert(const T& x);			//将新元素的关键码x插入到最小堆中
    bool Remove(T& x);					//删除堆顶的最小元素
    int GetMin();
    bool IsEmptmatric() const { return (currentSize == 0) ? true : false; }
    bool IsFull() const { (currentSize == maxHeapSize) ? true : false; }
    void MakeEmptmatric() { currentSize = 0; }   //内存并没有释放
    template<class R>
    friend ostream& operator<<(ostream& out, MinHeap<R>& hp);

private:
    T* heap;							//存放最小堆中元素关键码的数组
    int currentSize;					//最小堆中当前元素的个数
    int maxHeapSize;					//最小堆最多允许的元素个数
    void siftDown(int start, int m);	//从start到m下滑调整成为最小堆
    void siftUp(int start);				//从start到0上滑调整成为最小堆
};

template<class T>
MinHeap<T>::MinHeap(int sz) //参数再写int sz = DefaultSize报错
{
    maxHeapSize = sz;//实际中要对sz检查一下

    heap = new T[maxHeapSize];          //创建堆存储空间(就是简单的数组)
    if (heap == nullptr)
    {
        cerr << "内存分配失败" << endl;
        exit(1);
    }
    currentSize = 0;
}

template<class T>
MinHeap<T>::MinHeap(T arr[], int n)
{
    //maxHeapSize = (DefaultSize < n) ? n : DefaultSize;  //若n>DefaultSize，则堆是满的；否则堆不满(默认数组没有空的内存，存满了数据)

    maxHeapSize = n;


    heap = new T[maxHeapSize];
    if (heap == nullptr)
    {
        cerr << "内存分配失败！" << endl;
        exit(1);
    }

    //把数组arr复制到堆数组中
    for (int i = 0; i < n; i++)
    {
        heap[i] = arr[i];
    }

    currentSize = n;
    int currentPos = (currentSize - 1) / 2;		//找到最初调整的位置：最后拥有子女结点的结点即最后的那个父节点
    while (currentPos >= 0)                     //控制多次局部最小堆以实现全局都是最小堆
    {
        siftDown(currentPos, currentSize - 1);  //局部自上向下下滑调整。各个元素关键码的下表是从0开始算的，所以最后一个关键码的位置是currentSize - 1
        currentPos--;
    }
}

//最小堆的下滑调整算法（局部调整）
//虽然siftDown是私有权限，但是该权限是对对象而言的，类外实现的时候只需加作用域即可写代码实现该函数
template<class T>
void MinHeap<T>::siftDown(int start, int m)
{
    //从start结点开始到m节点位置，自上向下比较，如果子女的关键码小于父节点的关键码，则关键码小的上浮，继续往
    //下层比较，这样将以start为根节点的子树调整为局部的最小堆
    int i = start, j = 2 * i + 1;			//j是作左子女的位置

    while (j <= m)							//访问不超出m节点位置
    {
        if (j < m && heap[j + 1] < heap[j])
            j++;							//让j指向两子女的小者

        if (heap[j] > heap[i]) break;       //如果子女的关键码比父节点的大，则不做调整
        else  //关键码交换
        {
            T temp = heap[i];
            heap[i] = heap[j];				//小的关键码上浮
            i = j;							//更新根节点下表
            j = 2 * j + 1;					//新根节点的左子女下表
            heap[i] = temp;			        //大的关键码下沉到刚刚的子女位置
        }
    }

}

//最小堆的上滑调整算法,调整的是全局
template<class T>
void MinHeap<T>::siftUp(int start)
{
    //从start开始到结点0为止，自下向上比较，如果子女的关键码小于父节点的关键码，则相互交换。这样将集合重新调整为最小堆
    int j = start, i = (j - 1) / 2;			//和siftDown一样，j指向子女，i指向父节点

    while (j > 0)
    {
        if (heap[i] < heap[j]) break;		//如果父节点更小，则不用做调整
        else //关键码交换
        {
            T temp = heap[j];				//记录子女关键码
            heap[j] = heap[i];				//父节点关键码下移
            j = i;							//当前父节点作为上一层调整的子女结点
            i = (j - 1) / 2;				//新的父节点
            heap[j] = temp;					//小的关键码上浮
        }
    }

}

//插入元素的关键码总会放在已存在最小堆的最后面，然后将其与父节点的关键码进行比较，完成对调以形成新的最小堆
//关键码比较回调的过程用到了堆的上滑调整操作siftUp
template<class T>
bool MinHeap<T>::Insert(const T& x)
{
    //将新元素的关键码x插入到最小堆中
    if (currentSize == maxHeapSize)
    {
        cerr << "Heap Full!" << endl;
        return false;
    }

    heap[currentSize] = x;			//先将关键码放在堆的最后
    siftUp(currentSize);				//从最后的位置开始回调
    currentSize++;
    return true;
}


//删除堆顶的最小元素
template<class T>
bool MinHeap<T>::Remove(T& x)
{
    //删除堆顶的最小关键码后，一般以堆的最后一个元素填补该位置，并将currentSize减一。此时最小堆已被破坏，所以调用siftDown再次调整
    if (!currentSize)  //如果堆为空
    {
        cerr << "Heap Emptmatric!" << endl;
        return false;
    }

    x = heap[0];							//取堆顶最小关键码
    heap[0] = heap[currentSize - 1];		//最后的关键码补顶
    heap[currentSize - 1] = x;				//堆顶的元素放在数组的后面，虽然下一句currentSize--后不能再输出该值，但是可以为堆排序做铺垫
    currentSize--;
    siftDown(0, currentSize - 1);			//从堆顶向下调整为堆
    return true;
}

template<class T>
int MinHeap<T>::GetMin()
{
    return heap[0];
}

//堆的存储形式为完全二叉树，按照完全二叉树从上往下，从左往右的顺序依次输出个元素的关键码
template<class R>
ostream& operator<<(ostream& out, MinHeap<R>& hp)
{
    if (hp.currentSize == 0)
    {
        out << "Heap Emptmatric!" << endl;
    }
    else
    {
        for (int i = 0; i < hp.currentSize; i++)
            out << hp.heap[i] << " ";
    }
    out << endl;
    return out;
}


int main() {
    int m, n;
    cin >> m >> n;
    int* nums = new int[n+1];

    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }
    MinHeap<int> minheap(500000);//里面存X/M个最大的元素
    MaxHeap<int> maxheap(500000);//里面存X-X/M个剩下的元素
    int min_len=0;

    for (int i = 0; i < n; ++i) {
        int max1 = maxheap.GetMax();
        int max2 = minheap.GetMin();
        int k = ceil(((double)i + 1) / (double)m);
        if (k > min_len) {//就是最小堆要加元素了
            if (max1 <= nums[i]) {
                minheap.Insert(nums[i]);
            }
            else if (max1 > nums[i]) {
                //那就拿出大顶堆元素加入小顶堆里面，再把nums[i]加入大顶堆
                int temp;
                maxheap.RemoveMax(temp);
                minheap.Insert(temp);
                maxheap.Insert(nums[i]);
            }
            ++min_len;
        }
        else if (k == min_len) {
            //也就是X/M不变，小顶堆的数量不断，都是内部元素可能要调整
            if (nums[i] <= max2) {
                //说明最小堆不需要变
                maxheap.Insert(nums[i]);
            }
            else {
                int temp;
                minheap.Remove(temp);
                minheap.Insert(nums[i]);
                maxheap.Insert(temp);
            }
        }

        //最后取最小堆的头
        cout << minheap.GetMin() << " ";
    }

    return 0;
}