//
// Created by Pygmalion on 2021/11/25.
//
/**
 * 前缀和
 */
#include<iostream>
#include <vector>
#include<queue>

using namespace std;
const int N=100010;
int n,m;
int s[N];
queue<int> q;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        s[i]+=s[i-1]+x;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        cout<<s[y]-s[x-1]<<endl;
    }
    

}