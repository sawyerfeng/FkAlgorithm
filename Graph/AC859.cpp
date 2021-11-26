//
// Created by Pygmalion on 2021/11/22.
//
/**
* Kruskal算法
 *
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
const int N=20010;
int n,m;
int p[N];
struct Edge{
    int a,b,w;
    //重载<
    bool operator < (const Edge &e) const{
        return w<e.w;
    }
}edge[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    else return p[x];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }
    sort(edge,edge+m);
    int ans=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        //判断不连通
        a=find(a),b=find(b);
        if(a!=b){
            p[a]=b;//连通两个块
            cnt++;
            ans+=w;
        }
    }
    if(cnt<n-1) cout<<ans;
    else cout<<"impossible";
}

*/

#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=20010;
int p[N];
struct Edge{
    int a,b,w;
}edges[N];
bool  cmp(const Edge &a,const Edge &b){
    return a.w<b.w;
}
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    else return x;
}
int kruskal(){
    for(int i=1;i<=n;i++) p[i]=i;
    int cnt=0,ans=0;
    for (int i=0;i<m;i++){
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        int x=find(a),y=find(b);
        if(x!=y){
            p[x]=y;
            cnt++;
            ans+=w;
        }
    }
    if(cnt<n-1) return 0x3f3f3f3f;
    else return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    sort(edges,edges+m,cmp);
    int t=kruskal();
    if(t!=0x3f3f3f3f) cout<<t;
    else cout<<"impossible";
}