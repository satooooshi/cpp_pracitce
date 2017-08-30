#include<iostream>
using namespace std;

int main(){

  int num;
  int one;
  int ten;
  int hun;
  int tho;
  int arr[4];
  int buf1;
  int buf2;
  int i=0;

  cout<<"请输入一个4位整数:";
  cin>>num;

  one=num%10;
  ten=(num%100)/10;
  hun=(num%1000)/100;
  tho=num/1000;

  arr[0]=one;
  arr[1]=ten;
  arr[2]=hun;
  arr[3]=tho;

  buf1=arr[1];
  arr[1]=arr[3];
  arr[3]=buf1;

  buf1=arr[2];
  arr[2]=arr[0];
  arr[0]=buf1;

  for(i=0;i<4;++i)
  arr[i]+=10;

  for(i=0;i<4;++i)
  arr[i]-=7;

  for(i=0;i<4;++i)
  arr[i]=arr[i]%10;


  for(i=0;i<4;++i){
    cout<<arr[i];
  }
  cout<<'\n';

  return 0;
}
