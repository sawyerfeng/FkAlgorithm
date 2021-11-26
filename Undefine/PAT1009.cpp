//
// Created by Pygmalion on 2021/11/26.
//

#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> v;
int main(){
    while(1){
        string a;
        cin>>a;
        if(a.length()==0) break;
        else
            v.push_back(a);
    }
    for(int i=v.size()-1;i>=0;i--){
        if(i!=0)
            cout<<v[i]<<" ";
        else
            cout<<v[i];
    }

}