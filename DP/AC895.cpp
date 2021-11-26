//
// Created by Pygmalion on 2021/11/23.
//
/**
 * Acwing895,最长上升子序列
 */
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=1010;
int a[N],f[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int res=0;
    //不一定最后一个就是单调递增最长的结尾
    for(int i=1;i<=n;i++){
        res=max(res,f[i]);
    }
    cout<<res;
}

