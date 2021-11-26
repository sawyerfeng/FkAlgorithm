//
// Created by Pygmalion on 2021/11/6.
//
/***
 * 838. 堆排序
 * 输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。
 */
#include<iostream>
using namespace std;
const int N=100001;
int heap[N];
int size;
void down(int x){
    int tmp=x;
    if(2*x<=size&&heap[2*x]<heap[tmp]) tmp=2*x;
    if(2*x+1<=size&&heap[2*x+1]<heap[tmp]) tmp=2*x+1;
    if(tmp!=x){
        swap(heap[x],heap[tmp]);
        down(tmp);
    }

}
int main(){
int n,m;
cin>>n>>m;
size=n;
for(int i=1;i<=n;i++) cin>>heap[i];
for(int i=size/2;i;i--) down(i);
while(m--){
    cout<<heap[1]<<" ";
    heap[1]=heap[size];
    size--;
    down(1);
}
}
