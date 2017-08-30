#include<iostream>
using namespace std;

int main(){

  int num[2];
  int sum;
  int sub;
  int mult;
  int divd;
  int remain;

  cout<<"请输入两个整数";
  cin>>num[0]>>num[1];

  sum=num[0]+num[1];
  sub=num[0]-num[1];
  mult=num[0]*num[1];
  divd=num[0]/num[1];
  remain=num[0]%num[1];

  cout<<num[0]<<"+"<<num[1]<<"="<<sum<<'\n';
  cout<<num[0]<<"-"<<num[1]<<"="<<sub<<'\n';
  cout<<num[0]<<"*"<<num[1]<<"="<<mult<<'\n';
  cout<<num[0]<<"/"<<num[1]<<"="<<divd<<'\n';
  cout<<num[0]<<"%"<<num[1]<<"="<<remain<<'\n';

  return 0;
}
