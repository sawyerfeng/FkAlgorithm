//
// Created by Pygmalion on 2022/1/3.
//
#include<iostream>
#include<unordered_map>
using namespace std;
const int mod=1e9+7;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int> map;
    while(n--){
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++){
            while(x%i==0){
                x/=i;
                map[i]++;
            }
        }
        if(x>1) map[x]++;
    }
    long long res=1;

    for(auto m:map){
        long long t=1;
        int a=m.second,p=m.first;
        while(a--){
            t=(t*p+1)%mod;
        }
        res=res*t%mod;
    }
    cout<<res;
}
