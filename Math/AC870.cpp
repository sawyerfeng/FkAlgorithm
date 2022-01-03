//
// Created by Pygmalion on 2022/1/2.
//
#include<iostream>
#include<unordered_map>
using namespace std;
int n;
const int mod=1e9+8;
unordered_map<int,int> map;
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                while(x%i==0){
                    x/=i;
                    map[i]++;
                }
            }
        }
        if(x>1) map[x]++;

    }
    long long res=1;
    for(auto m:map){
        res=res*(m.second+1)%mod;
    }
    cout<<res<<endl;
}

