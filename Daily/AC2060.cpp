//
// Created by Pygmalion on 2022/1/4.
//
#include<iostream>
#include<vector>
using namespace std;
const int N=60;
char g[N][N];
int n,m;
int cnt;
typedef pair<int,int > PII;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y,vector<PII>& ps){
    g[x][y]='.';
    ps.push_back({x,y});
    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(g[a][b]=='X') dfs(a,b,ps);
    }

}
int main(){
    cin>>n>>m;
    vector<PII> points[2];
    for(int i=0;i<n;i++) cin>>g[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(g[i][j]=='X'){
                dfs(i,j,points[cnt++]);
            }
        }
    int ans=0x3f3f3f3f;
    for(auto i:points[0])
        for(auto j:points[1]){
            ans=min(ans,abs(i.first-j.first)+ abs(i.second-j.second)-1);
        }
    cout<<ans;

}
