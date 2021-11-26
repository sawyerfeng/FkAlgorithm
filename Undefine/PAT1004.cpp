//
// Created by Pygmalion on 2021/11/26.
//
/**
 * 1004 成绩排名 (20 分)
 * 利用优先队列，存储两个堆
 */

#include<iostream>
#include<queue>
using namespace std;
int n;
struct Stu{
    string name;
    string num;
    int score;
    bool operator > (const Stu &s)const{
        return score >s.score;
    }
    bool operator < (const Stu &s)const {
        return score <s.score;
    }
};
int main(){
    cin>>n;
    priority_queue<Stu,vector<Stu>,greater<Stu> > q1;
    priority_queue<Stu,vector<Stu>,less<Stu> > q2;
    for(int i=0;i<n;i++){
        string name,num;
        int score;
        cin>>name>>num>>score;
        Stu s={name,num,score};
        q1.push(s);
        q2.push(s);
    }
    cout<<q2.top().name<<" "<<q2.top().num<<endl;
    cout<<q1.top().name<<" "<<q1.top().num;
}