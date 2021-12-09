//
// Created by Pygmalion on 2021/12/8.
//
/**
 * AC1106山峰和山谷
 */
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int N=1010;
typedef pair<int,int> PII;
queue<int> p;
PII q[N*N];
int g[N][N];
bool st[N][N];
int peak,valley;
bool is_peak,is_valley;
void bfs(int sx,int sy){
    int hh=0,tt=0;
    q[0]={sx,sy};
    st[sx][sy]=true;
    while(hh<=tt){
        PII t=q[hh++];
        for(int i=t.first-1;i<=t.first+1;i++)
            for(int j=t.second-1;j<=t.second+1;j++){
                if(i<0||i>=n||j<0||j>=n) continue;
                if(g[t.first][t.second]>g[i][j]) is_peak=false;
                if(g[t.first][t.second]<g[i][j]) is_valley=false;
                if(t.first==i&&t.second==j) continue;
                if((g[t.first][t.second]==g[i][j])&&(!st[i][j])){
                    q[++tt]={i,j};
                    st[i][j]=true;
                }
            }
    }

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            cin>>g[i][j];
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            if(!st[i][j]){
                is_valley=true,is_peak=true;
                bfs(i,j);
                if(is_valley) valley++;
                if(is_peak) peak++;

            }
        }
    cout<<peak<<" "<<valley;
}

