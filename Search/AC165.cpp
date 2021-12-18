//
// Created by Pygmalion on 2021/12/18.
//
/**
 * AC165
 * 小猫爬山
 * DFS剪枝与优化
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N=30;
int n,w;
int c[N],sum[N];
int ans=N;
void dfs(int u,int k){//u 代表猫的数量，遍历所有猫. k代表车的数量
    if(k>=ans) return;
    if(u==n){
        ans=k;
        return;
    }
    for(int i=0;i<k;i++){//决策一，加入现有的车中
        if(c[u]+sum[i]<=w){
            sum[i]+=c[u];
            dfs(u+1,k);
            sum[i]-=c[u];
        }
    }
    //决策二，新开一辆车
    sum[k]=c[u];
    dfs(u+1,k+1);
    sum[k]=0;
}
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++){cin>>c[i];}
    sort(c,c+n);
    reverse(c,c+n);
    dfs(0,0);
    cout<<ans;

}

