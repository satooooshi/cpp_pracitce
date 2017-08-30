#include<iostream>
using namespace std;

int main(){

  int num;
  int one;
  int ten;
  int hun;
  int tho;
  int tth;
  int arr[5];

  cout<<"请输入一个5位正整数:";
  cin>>num;

  one=(num%10);
  ten=(num%100)/10;
  hun=(num%1000)/100;
  tho=(num%10000)/1000;
  tth=num/10000;

  arr[0]=one;
  arr[1]=ten;
  arr[2]=hun;
  arr[3]=tho;
  arr[4]=tth;

  if(arr[0]==arr[4] && arr[1]==arr[3])
    cout<<"Yes\n";
  else
    cout<<"No\n";

  return 0;
}
