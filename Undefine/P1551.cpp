//
// Created by Pygmalion on 2021/11/6.
//
/***
 * P1551 亲戚
 */
#include<iostream>
using namespace std;
const int N=1000001;
int f[N];
int find(int x){
    if(f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}
bool check(int a,int b){
    return find(a)==find(b);
}
int main(){
    int m,n,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        f[find(x)]=find(y);
    }
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        if(check(x,y))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}