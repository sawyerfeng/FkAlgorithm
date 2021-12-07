//
// Created by Pygmalion on 2021/11/28.
//
/**
 * P1387 最大正方形
 *  状态表示：f[i][j]表示以(i,j)为右下角的最大正方形边长。
 *  状态计算:f[i][j]=min(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
 *
EG:
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1
 */

#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=110;
int f[N][N];
int a[N][N];
int ans=-0x3f3f3f3f;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
            }
            //cout<<f[i][j]<<" ";
            ans=max(ans,f[i][j]);
        }
        //cout<<endl;
    }
    cout<<ans;

}
