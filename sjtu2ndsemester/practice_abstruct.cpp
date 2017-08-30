#include<iostream>
using namespace std;

//Base
class B{//abstruct class
public:
  virtual void f()=0;//pure virtual function
  virtual void g()=0;
};

//B b; -> error B is abstruct

//Derivative
class D1:public B{
public:
  void f()override;
  void g()override;
};

//Derivative
class D2:public B{
public:
  void f()override;
  //no g() -> g() still pure virtual function
};

//D2 d2 -> error D2 is still abstruct
//even a single member of D2 is abstruct then D2 will be abstruct

//both f() and g() is now overrided
class D3:public D2{
public:
  void g()override;
};

int main(){
  //D1 d1;
//D2 d2; error because g() hasnt overrided, or still pure function
  //D3 d3;//Ok both f() and g() were overrided
return 0;
}
