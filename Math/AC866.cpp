//
// Created by Pygmalion on 2022/1/1.
//
/*
 * 判定质数
 */
#include<iostream>
using namespace std;
int n;
int x;
void is_prim(int a){
    if(a<2) { cout << "Yes" << endl; return;}
    for(int i=2;i<=a/i;i++){
        if(a%i==0) { cout << "No"<<endl; return; }
    }
    cout<<"Yes"<<endl;

}

int main(){
    cin>>n;
    while(n--)
    {
        cin>>x;
        is_prim(x);
    }

    return 0;
}