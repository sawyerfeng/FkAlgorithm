//
// Created by Pygmalion on 2021/12/25.
//
/*
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct Sto{
    int id;
    int times;
    bool operator<(const Sto &S) const{
        return times<S.times;
    }
}sto[N];
int n,m,t;
bool is_good[N];
int store[N];
int cnt;
int main(){
    cin>>n>>m>>t;
    for(int i=0;i<m;i++){
        cin>>sto[i].times>>sto[i].id;
    }
    sort(sto,sto+m);
    for(int i=0;i<m;i++){
        if(sto[i].times>t) break;
            store[sto[i].id] += 2;
            for (int j = 1; j <= n; j++) {
                if (j != sto[i].id && store[j]) {
                    store[j]--;
                    if (store[j] <= 3&&is_good[j]) { is_good[j] = false;cnt--;};
                }
            }
            if (store[sto[i].id] > 5) { is_good[sto[i].id] = true;cnt++; };

    }
    cout<<cnt;

}
*/
//
// Created by Pygmalion on 2021/12/25.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct Sto{
    int id;
    int times;
    bool operator<(const Sto &S) const{
        return times<S.times;
    }
}sto[N];
int n,m,t;
bool is_good[N];
int store[N];
int last_store[N];
int cnt;
int main(){
    cin>>n>>m>>t;
    for(int i=0;i<m;i++){
        cin>>sto[i].times>>sto[i].id;
    }
    sort(sto,sto+m);
    for(int i=0;i<m;i++){
        int time=sto[i].times,id=sto[i].id;
        //如果不是上一个访问
        if(time!=last_store[id]){
            store[id]-=time-last_store[id]-1;
        }
        store[id]=max(0,store[id]);
        if(store[id]<=3) is_good[id]=false;
        store[id]+=2;
        if(store[id]>5) is_good[id]=true;
        last_store[id]=time;
    }
    for(int i=1;i<=n;i++){
        if(last_store[i]<t){
            store[i]-=t-last_store[i];
            if(store[i]<=3)
                is_good[i]=false;
        }
    }
    for(int i=1;i<=n;i++){
        if(is_good[i]) cnt++;
    }
    cout<<cnt;
}
