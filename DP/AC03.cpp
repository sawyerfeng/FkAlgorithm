//
// Created by Pygmalion on 2021/11/13.
//

/**
 * 动态规划
 * 之
 * 完全背包问题(正向循环)
 */
#include<iostream>
using namespace std;
int n,m;
const int N=1010;
int v[N],w[N];
int f[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    for(int j=v[i];j<=m;j++){
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;


}
