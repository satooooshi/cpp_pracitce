#include<iostream>
using namespace std;




int main(){

  int i=1;
  int &r=i;

  r++;
  cout<<i<<endl;

  // const keyword effects left value(cr cant be changed)
  const int &cr=i;
  i=5;
  i=3;
  cout<<i<<" "<<cr<<" "<<r<<endl;
  i++;
  cout<<i<<" "<<cr<<" "<<r<<endl;

  //cr=10; error const int &cr means cant change cr 'directly'.
  cout<<i<<endl;



  return 0;
}
