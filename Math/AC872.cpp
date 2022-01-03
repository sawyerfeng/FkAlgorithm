//
// Created by Pygmalion on 2022/1/3.
//
#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b ? gcd(b,a%b):a;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        cout<<gcd(x,y)<<endl;}

}

