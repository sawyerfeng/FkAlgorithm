//
// Created by Pygmalion on 2021/11/23.
//
/**
 * 最长上升子序列优化
 * 用到了二分+dp
 */
#include<iostream>
using namespace std;
const int N=100010;
int f[N],a[N];
int n;
int cnt ;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[++cnt]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>f[cnt]) f[++cnt]=a[i];
        else {
            int l=1,r=cnt;
            while(l<r){
                int mid=(l+r)>>1;
                if(f[mid]>=a[i]) r=mid;
                else l=mid+1;
            }
            f[l]=a[i];
        }
    }
    cout<<cnt;

}