//
// Created by fyz on 2023/12/2.
//chatgpt一遍过还没看题
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void computeLPSArray(const char* pat, int M, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(const char* pat, const char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    vector<int> lps(M, 0);
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    bool found = false;

    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << i - j << " ";
            found = true;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        cout << -1;
    }
}

int main() {
    int len1, len2;
    cin >> len1 >> len2;

    char s1[len1 + 1];
    char s2[len2 + 1];

    cin >> s1 >> s2;
    search(s2, s1);
    cout << endl;

    return 0;
}
