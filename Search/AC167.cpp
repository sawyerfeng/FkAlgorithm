//
// Created by Pygmalion on 2021/12/21.
//

/**
 * AC167
* 木棒问题，DFS剪枝
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,sum;
const int N=70;
int w[N];
bool st[N];
int length;
//u为大棍数量，s为现拼接棍长度，start指的是从哪里开始搜索
bool dfs(int u,int s,int start){
    if(u*length==sum) return true;
    if(s==length) return(dfs(u+1,0,0));//拼接成功一根棍
    for(int i=start;i<n;i++){
        if(w[i]+s>length) continue;
        if(st[i]) continue;
        st[i]=true;
        if(dfs(u,s+w[i],i+1)) return true;
        st[i]=false;
        //下面是失败回溯情况，需要对失败情况剪枝
        //开始结尾都为失败，则直接返回，这种情况就成立不了
        if(!s) return false;
        if(s+w[i]==length) return false;
        int j=i;
        while(j<n&&w[j]==w[i]) j++;
        i=j-1;

    }
    return false;

}
int main(){
    while(cin>>n,n){
        sum=0;
        memset(st,0,sizeof st);
        for(int i=0;i<n;i++){
            cin>>w[i];
            sum+=w[i];
        }
        sort(w,w+n);
        reverse(w,w+n);
        length=1;
        while(true){
            if(sum%length==0&&dfs(0,0,0)){
                cout<<length<<endl;
                break;
            }
            length++;
            if(length>sum) break;
        }
    }

}