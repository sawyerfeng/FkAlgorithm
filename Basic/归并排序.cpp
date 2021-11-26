/*
�鲢����
����˼�����ǣ�ѡȡ�е㣬һ��Ϊ�������󲻶�ϸ�֣�ÿ��С���������������������ٺϲ�
*/

#include<iostream>
using namespace std;
int n;
const int N=1e6+10;
int q[N],tmp[N];
void merge_sort(int q[],int l,int r){
    if(l>=r) return;//����
    int mid=(l+r)>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);//�������������Ѿ�����������������
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j])
        tmp[k++]=q[i++];
        else
        tmp[k++]=q[j++];
    } //�������������бȽϣ�С�ķŽ��������飬
    while(i<=mid) tmp[k++]=q[i++];//����ʣ�µĲ���
    while(j<=r) tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)
    q[i]=tmp[j];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    return 0;
}
