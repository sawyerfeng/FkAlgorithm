//
// Created by Pygmalion on 2021/12/9.
//
/**
 * AcWing 188. 武士风度的牛
 */
#include<iostream>
using namespace std;
int n,m;
typedef pair<int,int> PII;
const int N=200;
char g[N][N];
PII q[N*N];
const int dx[8]= {1,2,2, 1,-1,-2,-2,-1};//中国象棋马的正确走路姿势
const int dy[8]= {2,1,-1,-2,-2,-1,1,2};//一头不遵循国际象棋,而遵循中国象棋的外国牛-1,-2},{1,-2}};//方向数组
int stx,sty,edx,edy;
int dis[N][N];
void bfs(int sx,int sy){
    int hh=0,tt=0;
    q[0]={sx,sy};
    while(hh<=tt){
        PII t=q[hh++];
        for(int i=0;i<8;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>=n||b<0||b>=m||dis[a][b]||g[a][b]=='*') continue;
            if(a==edx&&b==edy){
                dis[a][b]=dis[t.first][t.second]+1;
                break;
            }
                q[++tt] = {a, b};
                dis[a][b] = dis[t.first][t.second] + 1;
        }
    }
}
int main(){
    memset(dis,0,sizeof dis);
    cin>>m>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            cin >> g[i][j];
            if(g[i][j]=='K')
                stx=i,sty=j;
            if(g[i][j]=='H')
                edx=i,edy=j;
        }
    bfs(stx,sty);
    cout<<dis[edx][edy];
}