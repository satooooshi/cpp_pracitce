#include<iostream>
#include<cmath>
using namespace std;

double sum;
double area;
double in_root;

double itv;
double i;

int main(){

  cout<<"输入小矩形的宽度: ";
  cin>>itv;


  while(i<1){
    in_root=1-i*i;
    area=itv*sqrt(in_root);//double sqrt(double)
    sum+=area;
    i+=itv;
  }

  cout<<"面积是, "<<sum<<'\n';
  return 0;
}
