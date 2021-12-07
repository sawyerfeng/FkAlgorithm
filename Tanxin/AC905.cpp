//
// Created by Pygmalion on 2021/12/7.
//
/**
 * AC905 区间选点
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct Range{
    int l,r;
   bool operator < (const Range &W) const{
       return r<W.r;
   }
}range[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&range[i].l,&range[i].r);
    }
    sort(range,range+n);
    int end=-0x3f3f3f3f;
    int ans=0;
    for(int i=0;i<n;i++){
        if(range[i].l>end){
            end=range[i].r;
            ans++;
        }
    }
    printf("%d",ans);



}
