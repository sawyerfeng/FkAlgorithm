//
// Created by Pygmalion on 2022/1/2.
//
#include<iostream>
using namespace std;
const int N=10010;
int st[N];
int primes[N],cnt;
int n;
void get_primes1(){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
        }
        for(int j=i;j<=n;j+=i){//用合数和质数来筛掉后面的合数
            st[j]=true;
        }
    }
    cout<<"prim1:"<<cnt<<endl;
}
void get_primes2(){
    memset(primes,0,sizeof primes);
    memset(st,0,sizeof st);
    cnt=0;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
            for(int j=i;j<=n;j+=i){
                st[j]=true;//只用质数就可以筛掉
            }
        }
    }
    cout<<"prim2:"<<cnt<<endl;
}
//欧拉筛法，线性筛
void get_primes3(){
    memset(primes,0,sizeof primes);
    memset(st,0,sizeof st);
    cnt=0;
    for(int i=2;i<=n;i++){//i充当倍数
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++){
            st[i*primes[j]]=true;
            if(i%primes[j]==0) break;
        }

    }
    cout<<"prim3:"<<cnt<<endl;
}
int main(){
    cin>>n;
    //get_primes1();
    //get_primes2();
    get_primes3();
}