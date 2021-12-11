//
// Created by Pygmalion on 2021/12/10.
//
/**
 * DFS  迷宫问题
 */
 /*
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
  */
#include<iostream>
using namespace std;
int n,m;
int stx,sty,edx,edy;
const int N=110;
char g[N][N];
bool st[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool dfs(int x,int y){
    if(g[x][y]=='#') return false;
    if(x==edx&&y==edy){
        return true;
    }
    st[x][y]=true;
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=m||b<0||b>=m) continue;
        if(st[a][b]) continue;
        if(dfs(a,b)) return true;
    }
    return false;
}
int main(){
    cin>>n;
    for(int q=0;q<n;q++) {
        cin>>m;
        memset(st,0,sizeof st);
        for (int i = 0; i < m; i++)
          cin>>g[i];
        cin >> stx >> sty >> edx >> edy;
        if(dfs(stx, sty)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}