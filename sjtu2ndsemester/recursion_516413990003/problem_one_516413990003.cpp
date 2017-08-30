//516413990003 会川慧
#include<iostream>
using namespace std;


//recursive fibonacci function
int fibo(int n) {
    if (n == 1 || n == 2){return n;}
    return fibo(n-1) + fibo(n-2);
}


int main(){

  int in;
  //cout<<"input : ";
  cin>>in;
  cout<<fibo(in)<<endl;

  return 0;
}
