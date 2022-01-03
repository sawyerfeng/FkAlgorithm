//
// Created by Pygmalion on 2021/12/22.
//

#include<iostream>
using namespace std;
const int N=1010;
int n,m;
char g[N][N];
int sx,sy;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool st[N][N];
int ans;
void  dfs(int x,int y){
    cout<<x<<" "<<y<<" "<<endl;
    if(x<1||x>n||y<1||y>n) return;
    if(st[x][y]) return;
    ans++;
    cout<<ans<<endl;
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(g[a][b]!=g[x][y]){
            st[a][b]=true;
            dfs(a,b);
        }
    }

}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    while(m--){
        memset(st,0,sizeof st);
        cin>>sx>>sy;
        dfs(sx,sy);
        cout<<ans;
    }
}