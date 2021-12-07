//
// Created by Pygmalion on 2021/11/30.
//
/**
 * AC840
 * HASH拉链法
 * HASH开放寻址法
 */

/*
#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=1e5+3; //取范围内第一个质数结果最好，冲突的可能性最小
int h[N],ne[N],e[N],idx;
void add(int a){
    int k=(a%N+N)%N;
    //cout<<k;
    e[idx]=a;
    ne[idx]=h[k];
    h[k]=idx++;
}
bool find(int a){
    int k=(a%N+N)%N;//牢记此公式，这样做是为了让负数在正数区间也能有映射值
    for(int i=h[k];i!=-1;i=ne[i]){
        if(e[i]==a)
            return true;
    }
    return false;


}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++){
        char a;
        int b;
        cin>>a>>b;
        if(a=='I'){
            add(b);
        }
        else{
            if(find(b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
*/
#include<iostream>
using namespace std;
const int N=2e5+3;//此方法要大于范围两倍，并且是第一个质数
const int INF=0x3f3f3f3f;
int h[N];
int n;
int find(int x){
    int k=(x%N+N)%N;
    while(h[k]!=x&&h[k]!=INF){
        k++;
        if(k==N) k=0;
    }
    return k;
}
int main(){
    cin>>n;
    memset(h,0x3f,sizeof h);
    for(int i=0;i<n;i++){
        char a;
        int b;
        cin>>a>>b;
        int t=find(b);
        if(a=='I'){
            h[t]=b;
        }
        else{
            if(h[t]==b)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

}
