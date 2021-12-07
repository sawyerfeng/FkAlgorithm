//
// Created by Pygmalion on 2021/12/7.
//
/**
 * AC148合并果子
 * 采用优先队列实现堆
 */

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n;
int ans;
priority_queue<int ,vector<int>,greater<int> > q;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        q.push(a);
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        //ans+=x+y;
        q.push(x+y);

    }
    ans=q.top();
    cout<<ans;
}


