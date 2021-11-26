//
// Created by Pygmalion on 2021/11/13.
//
/***
 * 动态规划
 * 之
 * 最长公共子序列问题
 */
/*
#include<iostream>
using namespace std;
int n,m;
const int N=1010;
char a[N],b[N];
int f[N][N];
int main(){
    cin>>n>>m;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i][j-1],f[i-1][j]);//必然存在的情况
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);//字符串相等的情况
            }
        }
    }
    cout<<f[n][m];

}
*/
#include<iostream>
using namespace std;
int n,m;
const int  =1010;
char a[N],b[N];
int f[N][N];
int main(){
    cin>>n>>m;
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m];
}
