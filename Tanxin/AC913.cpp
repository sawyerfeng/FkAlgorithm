//
// Created by Pygmalion on 2021/12/7.
//
/**
 * 排队打水
 */
#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long ans;
const int N=1e5+10;
int a[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        ans+=a[i]*(n-i-1);
    }
    cout<<ans;
}