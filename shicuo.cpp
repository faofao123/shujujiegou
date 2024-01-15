//
// Created by fyz on 2023/11/26.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[], char* envp[])
{
    cout << "参数的个数：" << argc << endl;
    for (int i = 0; i < argc; i ++ )
    {
        cout << "第" << i  << "个参数是：" << argv[i] << endl;
    }

    return 0;
}
