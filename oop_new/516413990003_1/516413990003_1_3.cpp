#include<iostream>
using namespace std;

int main(){

  int num;
  int one;
  int ten;
  int hund;

  cout<<"请输入一个三位整数:";
  cin>>num;

  one=(num%10);
  ten=(num%100-one)/10;
  hund=(num-ten)/100;

  cout<<num<<"的百位数字是"<<hund<<"十位数字是"<<ten<<"个位数字是"<<one<<'\n';

  return 0;
}
