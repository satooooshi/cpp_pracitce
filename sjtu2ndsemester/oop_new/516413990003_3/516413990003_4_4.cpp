#include<iostream>
using namespace std;

int main(){

  int val;
  int i;
  int j=0;
  int dot=1;

  cout<<"请输入一个奇整数:";
  cin>>val;
  
while(dot<=val){

  for(i=0;i<(val/2)-j;++i){
    cout<<" ";
  }
  j+=1;

  for(i=0;i<dot;++i){
    cout<<"*";
  }
  cout<<"\n";
  dot+=2;

  }

j=1;
dot=val;
while(dot>0){
  for(i=0;i<j;++i){
    cout<<" ";
  }
  j+=1;

  dot-=2;
  for(i=dot;i>0;--i){
    cout<<"*";
  }
  cout<<"\n";
}

  return 0;
}
