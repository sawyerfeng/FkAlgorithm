//
// Created by Pygmalion on 2021/11/26.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> s={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string a;
int main(){
    cin>>a;
    int sum=0;
    for(int i=0;i<a.length();i++){
        sum+=a[i]-'0';
    }
    bool sign=true;
    vector<int> v;
    while(sign){
        int a,b;
        a=sum/10;
        b=sum%10;
        sum=a;
        v.push_back(b);
        if(sum==0) {
            sign=false;
            break;
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i!=0)
        cout<<s[v[i]]<<" ";
        else cout<<s[v[i]];
    }


}
