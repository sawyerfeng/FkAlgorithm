//
// Created by Pygmalion on 2021/11/25.
//
/**
 * 区间dp
 * 先枚举区间长度
 * 再枚举左端点，找到右端点
 * 找状态转移方程
 */
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=310;
int s[N],f[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];//前缀和
    for (int len=2;len<=n;len++){//先枚举区间长度
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j]=1e8;
            for(int k=i;k<=j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
        }

    }
    cout<<f[1][n];
}
