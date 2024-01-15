//
// Created by fyz on 2023/12/6.
//chatgpt一遍过，没看题
#include <iostream>
#include <vector>

using namespace std;

bool canFormBST(vector<int>& postorder, int start, int end) {
    if (start >= end) return true;

    int rootVal = postorder[end];
    int i = start;

    while (i < end && postorder[i] < rootVal) {
        i++;
    }

    int j = i;
    while (j < end && postorder[j] > rootVal) {
        j++;
    }

    return j == end && canFormBST(postorder, start, i - 1) && canFormBST(postorder, i, end - 1);
}

int main() {
    int N;
    cin >> N;

    vector<int> postorder(N);
    for (int i = 0; i < N; ++i) {
        cin >> postorder[i];
    }

    bool result = canFormBST(postorder, 0, N - 1);

    if (result) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
