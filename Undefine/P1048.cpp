//
// Created by Pygmalion on 2021/11/14.
//
/**
 * P1048 [NOIP2005 普及组] 采药
 */
#include<iostream>
using namespace std;
int t,m;
const int N=1010;
int v[N],w[N];
int f[N];
int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=m;i++)
        for(int j=t;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    cout<<f[t];

}