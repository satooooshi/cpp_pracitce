#include<iostream>
using namespace std;

//x,y square left bottom point
// L length of square
void fractal(double x,double y,double l,int order,int cnt=1){
  if(order==0){
    cout<<"l:"<<l/4<<", order:"<<order<<endl;
  }
  else{
    cout<<"l:"<<l/4<<", order:"<<order<<endl;
    for(int i=0;i<4*cnt;++i){
      cout<<"   x:"<<l/4*i<<"   y:"<<l/4*i<<endl;
    }
    fractal(x,y,l/4,order-1,cnt*4);
  }
}


void fract(double x,double y,double l,int order){
  if(order==0){
    cout<<"l:"<<l<<", order:"<<order<<endl;
  }else{
  cout<<"l:"<<l<<", order:"<<order<<endl;
  cout<<"   x:"<<x<<"   y:"<<y<<endl;
  for(int i=1;i<=4;++i){
    fract(x*i,y*i,l/4,order-1);
  }
}
}

int main(){

    fractal(1,1,60,2);
    //fract(1,1,12,2);

  return 0;
}
