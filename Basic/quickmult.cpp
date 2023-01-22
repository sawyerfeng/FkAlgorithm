//快速乘
#include<iostream>
using namespace std;
int mult(int a,int b);
int main(){
    int a,b;
    cin>>a>>b;
    int ans=mult(a,b);
}
int mult(int a,int b){
    int ans=0;
    while(b){
        if(b&1) ans+=a;
        a+=a;
        b=b>>1;
        cout<<"a:"<<a<<"b:"<<b<<"ans:"<<ans<<endl;
    }
    return ans;
}