//
// Created by fyz on 2023/11/26.
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[10001];
    int l=0;
    for(int i=0;i<m;i++){
        string input,s;
        getline(cin, input,'#');
        stringstream ss(input);
        while(ss>>s){
            a[l]= stoi(s);
            l++;
        }
        for(int j=l-n;j<l;j++){
            a[j]=a[j+1];
        }
        l--;
        for(int j=0;j<l;j++){
            cout<<a[j]<<' ';
        }
        cout<<'#'<<endl;
    }
    return 0;
}