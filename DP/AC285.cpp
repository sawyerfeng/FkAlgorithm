//
// Created by Pygmalion on 2021/11/27.
//
/**
 * AC285 没有上司的舞会
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N=6010;
int n;
int f[N][2],w[N];// 内存开小
int ne[N],e[N],h[N],idx;
bool st[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int u){
    f[u][1]=w[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }

}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
        //标记为有父节点，即非根节点
        st[a]=true;
    }
    //找到根节点
    int root=1;
    while(st[root]) root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1]);
}