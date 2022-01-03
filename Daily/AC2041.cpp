//
// Created by Pygmalion on 2022/1/3.
//
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
const int N=1e6+10;
int a[N];
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int st,ed;
        cin>>st>>ed;
        a[st]++;
        a[ed+1]--;
    }
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    sort(a+1,a+n+1);
    cout<<a[n/2+1]<<endl;
}