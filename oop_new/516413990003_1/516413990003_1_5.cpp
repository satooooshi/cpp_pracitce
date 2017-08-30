#include<iostream>
#include<math.h>
using namespace std;

int main(){

  int x1;
  int y1;
  int x2;
  int y2;

  int dis_x;
  int dis_y;
  int dis;

  cout<<"请输入x1,y1:";
  cin>>x1>>y1;
  cout<<"请输入x2,y2:";
  cin>>x2>>y2;

  dis_x=x1-x2;
  dis_y=y1-y2;
  dis=(dis_x)*(dis_x)+(dis_y)*(dis_y);

  cout<<"("<<x1<<","<<y1<<")和("<<x2<<","<<y2<<")之间的距离:"<<sqrt(dis)<<'\n';

  return 0;
}
