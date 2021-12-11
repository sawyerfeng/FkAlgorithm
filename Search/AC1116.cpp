//
// Created by Pygmalion on 2021/12/10.
//
/**
 * AC1116. 马走日
 */
#include<iostream>
using namespace std;
int t,n,m,x,y;
const int N=20;
bool st[N][N];
int ans;
int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};
void dfs(int x,int y,int cnt){
    if(cnt==n*m) {
        ans++;
        return;
    }
    st[x][y]=true;
    for(int i=0;i<8;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0||a>=n||b<0||b>=m) continue;
        if(st[a][b]) continue;
        dfs(a,b,cnt+1);
    }
    st[x][y]=false;

}
int main(){
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>x>>y;
        memset(st,0,sizeof st);
        dfs(x,y,1);
        cout<<ans<<endl;
    }

}
