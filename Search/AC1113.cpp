//
// Created by Pygmalion on 2021/12/10.
//
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=30;
char g[N][N];
int stx,sty;
int ans;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int o,p;
void dfs(int x,int y){
    g[x][y]='#';//判断条件需要放到dfs开始部分
    ans++;
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=n||b<0||b>=m||g[a][b]=='#') continue;

        dfs(a,b);
    }
}
int main(){
    while(true) {
        ans=0;
        cin >> m >> n;
        if(m==0&&n==0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                if (g[i][j] == '@') {
                    stx = i, sty = j;
                }
            }
        dfs(stx, sty);
        cout << ans<<endl;
    }
}
