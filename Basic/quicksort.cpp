//qucik_sort
//2021.6.28 
#include<iostream>
using namespace std;
const int N=1e6+10;
int n;
int q[N];
void quick_sort(int a[],int start,int end){
	if(start>=end)
	return;
	int sign=a[(start+end)/2];//Ëæ»úÈ¡Êý»òÕßÖ±½ÓÈ¡ÖÐ¼äÖµ£¬·ñÔò»á³¬Ê±£¡ 
	int i=start-1;
	int j=end+1;//±ß½çÎÊÌâ£¡ 
	while(i<j){
		do i++;while(a[i]<sign);
		do j--;while(a[j]>sign);//×ó±ßÐ¡ÓÚÓÒ±ß´óÓÚ£¬·¢ÏÖ²»¶Ô½»»» 
		if(i<j) swap(a[i],a[j]); 
	}
	quick_sort(a,start,j);//µÝ¹é¿ìÅÅ×óÓÒ²¿·Ö 
	quick_sort(a,j+1,end);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>q[i];
	quick_sort(q,0,n-1);
	for(int i=0;i<n;i++)
	cout<<q[i]<<" ";
	return 0;
}
