//
// Created by Pygmalion on 2021/12/25.
//
#include<iostream>
#include<math.h>
using namespace std;
const int N=1e5+10;
int g[N];
int n;
int maxn=-0x3f3f3f3f;
int sum;
int tmp=-1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>g[i];
    }
    for(int i=1;i<=log(n)/log(2)+1;i++){
        sum=0;
        for(int j=0;j<pow(2,i-1);j++){
            int q=pow(2,i-1)+j;
            sum+=g[q];
            //cout<<g[q]<<" ";
        }
        if(sum>maxn) {
            maxn = max(sum, maxn);
            tmp = i;
        }
    }
    cout<<tmp;
}