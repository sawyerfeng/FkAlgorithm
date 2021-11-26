//
// Created by Pygmalion on 2021/11/10.
//
/***
 * 动态规划
 * 之
 * 01背包问题
 * 一维解法和二维解法
 */
#include<iostream>
using namespace std;
int n,m;
const int N=1010;
int v[N],w[N];
int f1[N][N];
int f2[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    //二维解法
    for(int i=1;i<=n;i++){//遍历商品
        for (int j=0;j<=m;j++){//遍历重量
            f1[i][j]=f1[i-1][j];//判断左集合，即不包含i集合，此情况一定存在
            if(j>=v[i]) f1[i][j]=max(f1[i][j],f1[i-1][j-v[i]]+w[i]);//判断右集合，即包含i集合，此情况要判断存在。
        }
    }
    cout<<f1[n][m]<<endl;

    //一维解法,利用滚动数组
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f2[j]=max(f2[j],f2[j-v[i]]+w[i]);
        }
    }
    cout<<f2[m]<<endl;
}