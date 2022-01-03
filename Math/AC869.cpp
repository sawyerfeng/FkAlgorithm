//
// Created by Pygmalion on 2022/1/2.
//
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> get_divisors(int n){
    vector<int> s;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            s.push_back(i);
            if(i!=n/i) s.push_back(n/i);
        }
    }
    sort(s.begin(),s.end());
    return s;

}
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        auto v=get_divisors(x);
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
