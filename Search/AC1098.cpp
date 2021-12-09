//
// Created by Pygmalion on 2021/12/8.
//
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int N=55,M=N*N;
int g[N][N];
typedef pair<int,int> PII;
PII q[M];
bool st[N][N];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};//采用这种方法进行上下左右访问
int bfs(int sx,int sy){
    int tt=0,hh=0;
    int area=0;
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt){
        area++;
        PII t=q[hh++];
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>=n||b<0||b>=m) continue;
            if(st[a][b]) continue;
            if(g[t.first][t.second]>>i&1) continue;
            q[++tt]={a,b};
            st[a][b]=true;
        }
    }
    return area;
}
int main(){
    cin>>n>>m;
    int area=0,cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!st[i][j]){
                area=max(area,bfs(i,j));
                cnt++;
            }
        }
    cout<<cnt<<endl;
        cout<<area;
}