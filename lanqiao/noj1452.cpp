//
// Created by Pygmalion on 2021/12/24.
//
/*
#include<iostream>
using namespace std;
long long sum;
int num;
bool check(int n) {
    while (n) {
        int a = n % 10;
        n = n / 10;
        if (a == 2 || a == 1 || (a == 0 && n) || a == 9) return true;
    }
    return false;
}
    int main(){
        for(int i=1;i<=2019;i++){
          if(check(i))
          {
              cout<<i<<endl;
              sum+=i*i;
              num++;
          }
        }
        cout<<sum<<" "<<num;
    }
*/
//利用string中find方法
#include<iostream>
#include<string>
using namespace std;
long long sum;
int main(){
    for(int i=1;i<=2019;i++){
        string s=to_string(i);
        if(s.find('2')!=string::npos||s.find('0')!=string::npos||s.find('1')!=string::npos||s.find('9')!=string::npos)
            sum+=i*i;
    }
    cout<<sum;
}

