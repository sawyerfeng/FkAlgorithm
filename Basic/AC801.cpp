//
// Created by Pygmalion on 2021/12/20.
//

/**
* AC801 二进制中1的个数
*/
#include<iostream>
using namespace std;
const int N=1e5+10;
int n;
int lowbit(int x){
    return x&(~x+1);
}
/*
int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        int res=0;
        while(a){
            a-=lowbit(a);
            res++;
        }
        cout<<res;
    }

}
 */
int main(){
    int n=9;
    cout<<(1<<9);
}