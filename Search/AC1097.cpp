//
// Created by Pygmalion on 2021/12/8.
//

/**
* BFS,FLOOD FILL
 * 宽搜框架
 * while(hh<=tt){
 *      t=q[hh++];//取队头
 *      for(){
 *          扩展
 *          q[++tt]=x; 加入队伍
 *      }
 * }
*/
#include<iostream>
using namespace std;
const int N=1010;
int n,m;
int cnt;
char g[N][N];
typedef pair<int,int> PII;
bool st[N][N];
PII q[N*N];//队列，手写
void bfs(int sx,int sy){
    int hh=0,tt=0;
    q[hh]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt) {
        PII t=q[hh++];
        for (int i = t.first-1; i <= t.first+1; i++)
            for (int j = t.second- 1; j <= t.second + 1; j++) {
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (g[i][j] == '.' || st[i][j]) continue;
                if (i == t.first && j == t.second) continue;
                q[++tt]={i,j};
                st[i][j]=true;
            }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>g[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j]=='W'&&!st[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    cout<<cnt;
}
