//
// Created by Pygmalion on 2021/11/26.
//
/**
 * P1359 租用游艇
 */

//dp解法
/*
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=210;
int a[N][N],f[N];
int main(){
    cin>>n;
    //memset(f,0x3f,sizeof f);
    for (int i=1;i<n;i++){
        f[i]=0x3f3f3f3f;
        for (int j=i+1;j<=n;j++){
            cin>>a[i][j];//存图
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            f[i]=min(f[i],f[j]+a[i][j]);
        }
    }
    cout<<f[1];
}
*/

#include<iostream>
using namespace std;
int n;
const int N=210;
int g[N][N];
int main(){
    cin>>n;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++){
        g[i][i]=0;
        for(int j=i+1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<n;i++){

    }

}

