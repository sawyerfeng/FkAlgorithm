//
// Created by Pygmalion on 2021/11/24.
//
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=1010;
char a[N],b[N];
int f[N][N];
int main(){
    cin>>n;
    cin>>a+1;
    cin>>m;
    cin>>b+1;
    for(int i=1;i<=m;i++) f[0][i]=i;//前0个a和i个b匹配，只能添加i
    for(int i=1;i<=n;i++) f[i][0]=i;//前i个a和0个b匹配，只能删除i
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
          if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
          else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
            }
        }
    cout<<f[n][m];
    }



