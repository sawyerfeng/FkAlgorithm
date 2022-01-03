//
// Created by Pygmalion on 2021/12/24.
//

#include<iostream>
using namespace std;
int a,b,c,d;
int main(){
    a=1;
    b=1;
    c=3;
    for(int i=5;i<=20190324;i++ ){
        d=(a+b+c)%10000;
        a=b;
        b=c;
        c=d;
    }
    cout<<d;
}