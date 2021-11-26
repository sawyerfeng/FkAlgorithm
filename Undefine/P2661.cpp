//
// Created by Pygmalion on 2021/11/5.
//
/***
 * P2661 [NOIP2015 提高组] 信息传递 题解
 */
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int f[200002],d[200002],n,minn,last;   //f保存祖先节点，d保存到其祖先节点的路径长。
int find(int x){
    if(f[x]!=x){
        int tmp=f[x];
        f[x]= find(f[x]);
        d[x]+=d[tmp];
    }
    return f[x];
}
void check(int a,int b){
    int x,y;
    x=find(a);y=find(b);
    if(x!=y){
        f[x]=y;
        d[a]=d[b]+1;
    }else minn=min(minn,d[a]+d[b]+1);
    return;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    memset(d,0,sizeof(d));
    minn=0x7777777;
    for(int i=1;i<=n;i++) {
        int t;
        cin>>t;
        check(i,t);//i->t
    }
    cout<<minn;
return 0;
}