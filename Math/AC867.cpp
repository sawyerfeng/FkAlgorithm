//
// Created by Pygmalion on 2022/1/2.
//
/*
 * 分解质因数
 */
#include<iostream>
using namespace std;
void divide(int n){
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            int s=0;
            while(n%i==0){
                n/=i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }

    }
    if(n>1) cout<<n<<" "<<1<<endl;
    cout<<endl;
}
int main(){
     int n;
     cin>>n;
     while(n--){
        int x;
        cin>>x;
        divide(x);
     }
}
