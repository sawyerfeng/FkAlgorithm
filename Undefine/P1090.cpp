//
// Created by Pygmalion on 2021/11/7.
//
/***
 * P1090 [NOIP2004 提高组] 合并果子 / [USACO06NOV] Fence Repair G
 *
 */
#include<iostream>
using namespace std;
const int N=100001;
int heap[N];
int sz;
void down(int x){
    int tmp=x;
    if(x*2<=sz&&heap[x*2]<heap[x]) tmp=2*x;
    if(x*2+1<=sz&&heap[x*2+1]<heap[x]) tmp=2*x+1;
    if(x!=tmp){
        swap(heap[x],heap[tmp]);
        down(tmp);
    }
}

int main(){
    int sum=0,tmp=0;
    int n;
    cin>>n;
    sz=n;
    for(int i=1;i<=n;i++){
        cin>>heap[i];
    }
    for(int i=n/2;i;i--){
        down(i);
    }
while(n>1){
    int p1,p2;
    p1=heap[1];
    heap[1]=heap[n--];
    down(1);
    p2=heap[1];
    sum+=p1+p2;
    heap[1]=p1+p2;
    down(1);
}
    cout<<sum;

}