//
// Created by fyz on 2023/11/30.
//chatgpt一遍过？我题干还没看呢（苦笑）；
#include <stdio.h>

// 交换数组中两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 将数组按照基准元素的大小分成两部分，并返回基准元素的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准元素
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] >= pivot) { // 如果当前元素大于等于基准元素，交换位置
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); // 将基准元素放到正确的位置
    return i + 1;
}

// 使用快速选择算法找到第 k 大元素
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }

    return -1; // 如果数组为空或 k 超出范围，返回 -1 或其他合适的值
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int result = quickSelect(arr, 0, n - 1, k);
    printf("%d\n", result);

    return 0;
}
