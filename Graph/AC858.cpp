//
// Created by Pygmalion on 2021/11/24.
//
/**
 * Prim算法
 */
#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
int g[N][N],dist[N];
bool st[N];
int n,m;
int ans=0;
int  prim(){
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        if(i&&dist[t]==0x3f3f3f3f) return 0x3f3f3f3f;
        if(i) ans+=dist[t];
        st[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[t][j]);
        }

    }
    return ans;
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b]=g[b][a]=min(g[a][b],w);
    }
    int t=prim();
    if(t==0x3f3f3f3f) cout<<"impossible";
    else cout<<ans;
}
