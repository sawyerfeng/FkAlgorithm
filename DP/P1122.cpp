//
// Created by Pygmalion on 2021/11/27.
//
//
// Created by Pygmalion on 2021/11/27.
//
//
// Created by Pygmalion on 2021/11/27.
//
#include<iostream>
#include<cstring>
using namespace std;
const int N=32020;
int ne[N],e[N],h[N],idx;
int n,w[N];
int f[N];
bool st[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int u,int fa){
    f[u]=w[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j!=fa) {
            dfs(j,u);
            if(f[j]>0){
                f[u]+=f[j];
            }

        }
    }
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ans= max(ans,f[i]);
    }
    cout<<ans;

}

/*
#include<iostream>
#include<vector>
using namespace std;
int n;
const int N=16010;
vector<int> g[N];
int f[N],w[N];
void dfs(int u,int fa){
    f[u]=w[u];
    for(int i=1)
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
}
*/