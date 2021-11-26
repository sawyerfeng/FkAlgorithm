//
// Created by Pygmalion on 2021/11/23.
//
/**
 * Acwing898
 */
//正推，向下走

#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=510;
int g[N][N], d[N][N];
const int INF=0x3f3f3f3f;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            d[i][j]=max(g[i][j]+d[i-1][j],g[i][j]+d[i-1][j-1]);
        }
    int res=-INF;
    for(int i=1;i<=n;i++) res=max(res,d[n][i]);
    cout<<res<<endl;
}


//倒推，向上爬
/*
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=510,INF=0x3f3f3f3f;
int f[N][N],g[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cin>>g[i][j];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            f[i][j]=g[i][j]+max(f[i+1][j],f[i+1][j+1]);
        }
    }
    cout<<f[1][1];
}
*/