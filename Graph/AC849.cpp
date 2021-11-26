//
// Created by Pygmalion on 2021/11/26.
//

#include<iostream>
#include<cstring>
const int N=510;
int dist[N];
int n,m;
int g[N][N];
bool st[N];
using namespace std;
int  dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
                //st[t]=true; 不可放到此处，要循环判定完毕后再加入。
            }
        }
        st[t]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];

}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    cout<<dijkstra();
}
