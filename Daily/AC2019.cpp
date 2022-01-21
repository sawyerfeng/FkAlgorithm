//
// Created by Pygmalion on 2022/1/5.
//
#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
const int N=1010;
int sx,sy;
int g[N][N];
int dist[N][N];
bool st[N][N];
typedef pair<int,int> PII;
deque<PII> q;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int bfs(int x,int y){
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    dist[x][y]=0;
    q.push_back({x,y});
    st[x][y]=true;
    while(q.size()){
        auto t=q.front();
        q.pop_front();
        if(t.first==0&&t.second==0) return dist[0][0];
        for(int i=0;i<4;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>=1002||b<0||b>=1002) continue;
            if(st[a][b]) continue;
            st[a][b]=true;
            if(dist[a][b]>dist[t.first][t.second]+g[a][b])
                dist[a][b]=dist[t.first][t.second]+g[a][b];
            if(g[a][b]) q.push_back({a,b});
            if(!g[a][b]) q.push_front({a,b});
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    cin>>sx>>sy;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a][b]=1;
    }
    cout<<bfs(sx,sy);
}