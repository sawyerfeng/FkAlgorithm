//
// Created by Pygmalion on 2021/12/8.
//
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=1010;
int g[N][N];
typedef pair<int,int> PII;
PII q[N*N];
PII mem[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void bfs(int sx,int sy){
    memset(mem,-1,sizeof mem);
    mem[sx][sy]={0,0};
    int hh=0,tt=0;
    q[0]={sx,sy};
    while(hh<=tt){
        PII t=q[hh++];
        for(int i=0;i<4;i++) {
            int a = t.first+dx[i], b = t.second+dy[i];
            if(a<0||a>=n||b<0||b>=n) continue;
            if(mem[a][b].first!=-1) continue;
            if(g[a][b]) continue;
            q[++tt]={a,b};
            mem[a][b]=t;

        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    bfs(n-1,n-1);
    PII it={0,0};
    while(true){
        cout<<it.first<<" "<<it.second<<endl;
        if(it.first==n-1&&it.second==n-1) break;
        else {
            it=mem[it.first][it.second];
        }
    }

}
