//
// Created by Pygmalion on 2021/11/30.
//
/*
 * AC791高精度加法
 */
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+10;
string a,b;
vector<int> A;
vector<int> B;
vector<int> C;
void add(vector<int>(A), vector<int>(B)){
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t=t/10;
    }
    if(t) C.push_back(1);
}
int main(){
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--){
        A.push_back(a[i]-'0');
    }
    for(int i=b.size()-1;i>=0;i--){
        B.push_back(b[i]-'0');
    }
    add(A,B);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
}

