#include<iostream>

class Point{
public:
  explicit Point(int a=0, int b=0){x=a, y=b;}
  explicit Point(const Point &p){x=2*p.x; y=2*p.y;}//copy constructor!!
  //assign operator= ,or(thief value)operator and [iterator] must be a member function
  void print(){std::cout<<x<<" "<<y<<std::endl;}
private:
  int x;
  int y;
};


int main(){

//constructor
  Point p1(10,20);
  p1.print();

//copy constructor
  Point p2(p1);
  p2.print();
//======copy constructor when not "explicit Point(const Point &p)"
//assign operator= (automatically generated)when explicit Point(const Point &p);
  Point p3;
  p3=p1;
  p3.print();
//constructor
  Point p4(1,2);
  p4.print();
//assign operator=
  p4=p1;
  p4.print();

  return 0;
}
