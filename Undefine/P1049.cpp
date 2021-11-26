//
// Created by Pygmalion on 2021/11/14.
//
/**
 * 装箱问题
 * 有一个箱子容量为VV（正整数，0 \le V \le 200000≤V≤20000），同时有nn个物品（0<n \le 300<n≤30，每个物品有一个体积（正整数）。
    要求nn个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
 */

/**
 * 此为0，1背包问题，一维空间优化只需要逆序循环即可
 */
#include<iostream>
using namespace std;
int v,n;
const int N=20010;
int w[N];
int f[N];
int main(){
    cin>>v>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];//读入体积
    }
    for(int i=1;i<=n;i++)
        for(int j=v;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    cout<<v-f[v];

}