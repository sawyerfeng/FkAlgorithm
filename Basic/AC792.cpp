//
// Created by Pygmalion on 2021/11/30.
//
/**
 * AC792 高精度减法
 */
#include<iostream>
#include<vector>
using namespace std;
string a,b;
vector<int> A,B,C;
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size()) return A.size()>B.size();//位数比较
    else{
        for(int i=A.size()-1;i>=0;i--)
            if(A[i]!=B[i]) return A[i]>B[i];//位数相同，比较不同的值
    }
    return true;//全部相同，为true
}
vector<int> sub(vector<int> &A,vector<int> &B){
    int t=0;
    for(int i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        //若为负数则说明借位了，则要将借位置为1
        if(t<0) t=1;
        else t=0;
    }
    //避免出现001状态
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
int main(){
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
        B.push_back(b[i]-'0');
    if(cmp(A,B)){//A>B
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--){
            cout<<C[i];
        }
    }else{
        cout<<"-";
        auto C=sub(B,A);
        for(int i=C.size()-1;i>=0;i--){
            cout<<C[i];
        }
    }

}
