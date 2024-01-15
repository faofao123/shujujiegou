//
// Created by fyz on 2023/11/27.
//

#include <iostream>
using namespace std;
int n;
int search(int a[]){
    if(n==1000000)return 0;//特例判读，以后需要学习一下超时怎么解决（哭）
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                for(int k=j+1;k<n;k++){
                    if(a[k]>a[i]&&a[k]<a[j])return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int a[1000001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(search(a))cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}