#include<iostream>
using namespace std;

void basic_capture(){
  auto plus=[](int a,int b){return a+b;};
  cout<<plus(3,5)<<endl;
}

void copy_capture(){
  int a=0;
  auto f=[=]{return a;};//[a]
  a=1;
  int result=f();//==0
  cout<<result<<endl;
}

void reference_capture(){
  int b=0;
  auto g=[&]{return b;};//[&b]
  b=1;
  int result=g();//==1
  cout<<result<<endl;
}

int main(){

  basic_capture();
  copy_capture();
  reference_capture();

  return 0;
}
