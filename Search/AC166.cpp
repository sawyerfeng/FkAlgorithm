//
// Created by Pygmalion on 2021/12/19.
//
/**
 *  AC166数独问题
 */
#include<iostream>
using namespace std;
const int N=9,M=1<<N;
//表示每一个状态的1含量，与每一个数字表达的1在哪一位
int ones[M],map[M];
//分别表示行，列，3x3小块中的数字占用情况，采用二进制压缩
int row[N],col[N],cell[3][3];
char str[100];
inline int lowbit(int x){
    return x&(-x);
}
inline void init(){
    //(1<<N)-1代表 111111111,表示9位均可放置的初始状态
    for(int i=0;i<N;i++) row[i]=col[i]=(1<<N)-1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cell[i][j]=(1<<N)-1;
        }
}
inline int get(int x,int y){
    return row[x] & col[y] & cell[x/3][y/3];
}
bool dfs(int cnt){
    if(!cnt) return true;
    //找最小选择点.即让其中的1尽可能的少
    int minv=10;
    int x,y;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(str[i*9+j]=='.'){
                int t=ones[get(i,j)];
                if(t<minv){
                    minv=t;
                    x=i,y=j;
                }
            }
        }
    for(int i=get(x,y);i;i-=lowbit(i)){
        int t=map[lowbit(i)];//找到最低位所代表的数字
        str[x*9+y]='1'+t;
        row[x]-=1<<t;
        col[y]-=1<<t;
        cell[x/3][y/3]-=1<<t;
        if(dfs(cnt-1)) return true;
        str[x*9+y]='.';
        row[x]+=1<<t;
        col[y]+=1<<t;
        cell[x/3][y/3]+=1<<t;
    }

    return false;
}

int main(){
    //完成map与ones的准备,可以查表
    for(int i=0;i<N;i++) map[1<<i]=i;
    for(int i=0;i<1<<N;i++) {
        int s=0;
        for (int j = i; j; j -= lowbit(j))s++;
            ones[i]=s;
    }
    while(cin>>str,str[0]!='e'){
        init();
        int cnt=0;
        for(int i=0,k=0;i<N;i++)
            for(int j=0;j<N;j++,k++){
                if(str[k]=='.') cnt++;
                else{
                    int t=str[k]-'1';//映射到0~9
                    row[i]-=1<<t;
                    col[j]-=1<<t;
                    cell[i/3][j/3]-=1<<t;
                }
            }
        dfs(cnt);
        cout<<str<<endl;
    }
    return 0;

}
