//
// Created by Pygmalion on 2021/12/22.
//
/**
 * P1706 全排列问题
 */
#include<iostream>
using namespace std;
int n;
const int N=10;
int a[N];
bool st[N];
void dfs(int u){
    if(u>n) {
        for(int i=1;i<=n;i++){
            cout<<"    "<<a[i];
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            a[u]=i;
            dfs(u+1);
            st[i]=false;
            a[u]=0;
        }
    }


}
int main(){
    cin>>n;
    dfs(1);

}
