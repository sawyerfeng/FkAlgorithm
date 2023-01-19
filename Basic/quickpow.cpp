//快速幂
#include<iostream>
using namespace std;
int pow(int a,int b){
    int ans;
    while(b!=0){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
        cout<<"a:"<<a<<"b:"<<b<<"ans:"<<ans<<endl;
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    int ans=pow(a,b);
    cout<<ans;
}
