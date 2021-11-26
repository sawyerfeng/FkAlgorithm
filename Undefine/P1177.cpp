//
// Created by Pygmalion on 2021/11/3.
//
#include<iostream>
using namespace std;
const int N=100001;
int q[N];
void qsort(int a[],int l,int r){
    if(l>=r) return;
    int mid;
    mid=a[(l+r)/2];
    int i=l-1,j=r+1;
    while(i<j) {
        while (a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    qsort(a,l,j);
    qsort(a,j+1,r);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    qsort(q,0,n-1);
    for(int i=0;i<n;i++){
        cout<<q[i]<<" ";
    }
    return 0;
}

