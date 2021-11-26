//
// Created by Pygmalion on 2021/11/23.
//

/**
* 数的范围
 * 二分法
*/

//二分模板
/*
bool check(int x){}
int bsearch_1(int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
}
int bsearch_2(int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
}

*/
#include<iostream>
using namespace std;
int n,q;
const int N=100010;
int a[N];

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int x=0;
        cin>>x;
        int l=0,r=n-1;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        if(a[l]!=x) cout<<"-1 -1"<<endl;
        else{
            cout<<l<<" ";
            int l=0,r=n-1;
            while(l<r){
                int mid=l+r+1>>1;
                if(a[mid]<=x) l=mid;
                else r=mid-1;
            }
            cout<<l<<endl;
        }

    }

}
