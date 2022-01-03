//
// Created by Pygmalion on 2021/12/22.
//
#include<iostream>
#define x first
#define y second
using namespace std;
int n,m;
const int N=1010;
char g[N][N];
bool st[N][N];
int cnt;
typedef pair<int,int> PII;
PII q[N*N];
void bfs(int sx,int sy){
    int tt=0,hh=0;
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt){
        PII t=q[hh++];
        for(int i=t.x-1;i<=t.x+1;i++){
            for(int j=t.y-1;j<=t.y+1;j++){
                if(i==t.x&&j==t.y) continue;
                if(i<0||i>=n||j<0||j>=m) continue;
                if(st[i][j]||g[i][j]=='.') continue;
                st[i][j]=true;
                q[++tt]={i,j};
            }
        }
    }
}
bool check(int x,int y)
{
    int ans=0;
    if(g[x][y]=='#') cnt++;
    if(g[x+1][y]=='#') cnt++;
    if(g[x][y+1]=='#') cnt++;
    if(g[x+1][y+1]=='#') cnt++;
    return ans==3;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=1;i<n;i++) //特殊情况的判断
        for(int j=1;j<m;j++)
            if(check(i,j))
            {
                printf("Bad placement.\n");
                return 0;
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j]=='#' &&!st[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    if(cnt)
    printf("There are %d ships",cnt);
    else
        cout<<"Bad placement.";
}
