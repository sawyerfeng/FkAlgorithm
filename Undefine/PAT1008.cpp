//
// Created by Pygmalion on 2021/11/26.
//
/**
 * 1008 数组元素循环右移问题 (20 分)
 */
#include<iostream>
using namespace std;
const int N=210;
int n,m;
int q[N],tt=-1,hh=0;

int main(){
    cin>>n>>m;
    m=m%n;//必须有这个, 否则会出现循环
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q[++tt]=a;
    }
    for(int i=0;i<n-m;i++){
        q[++tt]=q[hh++];
    }
    for(int i=n-1;i>=0;i--){
        if(i)
            cout<<q[hh++]<<" ";
        else
            cout<<q[hh]<<endl;
    }



}