//
// Created by Pygmalion on 2021/11/14.
//
#include<iostream>
using namespace std;
int n;
const int N=1010;
int path[N];
int vis[N];
void dfs(int u){
    if(u==n){//dfs出口
        for(int i=0;i<n;i++) cout<<path[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            vis[i] = true;
            path[u] = i;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
}
