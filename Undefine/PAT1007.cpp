//
// Created by Pygmalion on 2021/11/26.
//
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
const int N=10010;
int n;
vector<int> p;
bool isPrim(int a){
    int k=sqrt(a);
    bool sign=false;
    for(int i=2;i<=k;i++){
        if(a%i==0)  {sign=true;break;}
    }
    //cout<<a<<" "<<sign<<endl;
    return sign;
}
int main(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!isPrim(i)) p.push_back(i);
    }
   for(int i=p.size()-1;i>0;i--){
       if(p[i]-p[i-1]==2){
           cnt++;
       }
   }
   cout<<cnt;




}
