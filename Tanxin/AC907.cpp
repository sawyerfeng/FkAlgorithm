#include<iostream>
#include<algorithm>
using namespace std;
int n;
int st,ed;
int ans;
bool flag;
const int N=1e5+10;
struct Range{
    int l,r;
    bool operator < (const Range &W) const{
        return l<W.l;
    }
}range[N];
int main(){
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;i++) cin>>range[i].l>>range[i].r;
    sort(range,range+n);
    for(int i=0;i<n;i++){
        int max_r=-0x3f3f3f3f;
        int j=i;
        while(j<n&&range[j].l<=st){
            max_r=max(max_r,range[j].r);
            j++;
        }
        if(max_r<st){
            ans=-1;
            break;
        }
        ans++;
        if(max_r>=ed){
            flag=true;
            break;
        }
        st=max_r;
        i=j-1;
    }
    if(!flag) ans=-1;
    cout<<ans;
}